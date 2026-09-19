#!/bin/sh

cat << EOF >/dev/null

Task
Implement a program in minimum bytes of source or binary code that does voice recognition of a voice sample (me saying "yes", "yeah" or "no" in voice or in whisper, plainly or quirkily) based on training samples with maximum accuracy.

The program should read train/yes0.wav, train/no0.wav, train/yes1.wav and so on (there are 400 yeses and 400 noes in training dataset), then start reading inputs/0.wav, inputs/1.wav until it fails to find the file, analysing it and outputting "yes" or "no" (or other word for intermediate answer).

If you want, you may pre-train the program instead of reading train/, but the resulting data table counts towards the score (and beware of overfitting to training samples - they don't overlap with examination ones). Better to include the program used to produce the data table as an addendum in this case.

All sample files are little endian 16-bit stereo WAV files, just from laptop mic, without filtering/noise reduction.

Limits
Forbidden features:

Using network;
Trying to reach the answers file inputs/key;
Subverting the runner program that calculates accuracy;
Using existing recognition libraries. Linking to FFT implementation not allowed: only external math functions taking constant amount of information (like sin or atan2) are allowed; If you want FFT, just add it's implementation to your program source code (it can be multilingual if needed).
Resource limits:

The program should not take more than 30 minutes of CPU time on my i5 laptop. If it takes more, only output produced in the first 30 minutes are counted and eveything else is assumed a half-match;
Memory limit: 1GB (including any temporary files);
Tools
The tools/runner program automatically runs your solution and calculates the accuracy.

$ tools/runner solutions/example train train/key
Accuracy: 548 ‰
It can examine the program using training data or using actual exam data. I'm going to try submitted answers on examination dataset and publish results (accuracy percentage) until I make the dataset public.

Scoring
There are 5 classes of solution depending on accuracy:

All samples guessed correctly: Class 0;
Accuracy 950-999: Class 1;
Accuracy 835-950: Class 2;
Accuracy 720-834: Class 3;
Accuracy 615-719: Class 4;
Inside each class, the score is number of bytes the solution takes.

Accepted answer: smallest solution in the best nonempty class.

Links
Github project with tools: https://github.com/vi/codegolf-jein
Training dataset: http://vi-server.org/pub/codegolf-jein-train.tar.xz
Examination dataset is kept private so far, there are checksums (HMAC) available in the Github repository.
All samples should be considered CC-0 (Public Domain), scripts and programs should be considered MIT.

Example solution
It provides very poor quality of recognition, just shows how to read files and output answers

#define _BSD_SOURCE
#include <stdio.h>
#include <assert.h>
#include <endian.h>


#define Nvols 30

#define BASS_WINDOW 60
#define MID_WINDOW 4

struct training_info {
    double bass_volumes[Nvols];
    double mid_volumes[Nvols];
    double treble_volumes[Nvols];
    int n;
};


struct training_info yes;
struct training_info no;

static int __attribute__((const)) mod(int n, int d) {
    int m = n % d;
    if (m < 0) m+=d;
    return m;
}

// harccoded to 2 channel s16le
int get_file_info(const char* name, struct training_info *inf) {
    FILE* in = fopen(name, "rb");

    if (!in) return -1;

    setvbuf(in, NULL, _IOFBF, 65536);

    inf->n = 1;

    fseek(in, 0, SEEK_END);
    long filesize = ftell(in);
    fseek(in, 128, SEEK_SET);
    filesize -= 128; // exclude header and some initial samples

    int nsamples = filesize / 4;

    double bass_a=0, mid_a=0;
    const int HISTSIZE  = 101;
    double xhistory[HISTSIZE];
    int histpointer=0;
    int histsize = 0;

    //FILE* out = fopen("debug.raw", "wb");

    int i;
    for (i=0; i<Nvols; ++i) {
        int j;

        double total_vol = 0;
        double bass_vol = 0;
        double mid_vol = 0;
        double treble_vol = 0;

        for (j=0; j<nsamples / Nvols; ++j) {
            signed short int l, r; // a sample
            if(fread(&l, 2, 1, in)!=1) break;
            if(fread(&r, 2, 1, in)!=1) break;
            double x = 1/65536.0 * ( le16toh(l) + le16toh(r) );


            bass_a += x;
            mid_a  += x;


            if (histsize == HISTSIZE-1) bass_a   -= xhistory[mod(histpointer-BASS_WINDOW,HISTSIZE)];
            if (histsize == HISTSIZE-1) mid_a    -= xhistory[mod(histpointer-MID_WINDOW ,HISTSIZE)];

            double bass = bass_a / BASS_WINDOW;
            double mid = mid_a / MID_WINDOW - bass;
            double treble = x - mid_a/MID_WINDOW;

            xhistory[histpointer++] = x;
            if(histpointer>=HISTSIZE) histpointer=0;
            if(histsize < HISTSIZE-1) ++histsize;

            total_vol  += bass*bass + mid*mid + treble*treble;
            bass_vol   += bass*bass;
            mid_vol    += mid*mid;
            treble_vol += treble*treble;


            /*
            signed short int y;
            y = 65536 * bass;

            y = htole16(y);
            fwrite(&y, 2, 1, out);
            fwrite(&y, 2, 1, out);
            */
        }

        inf->bass_volumes[i] = bass_vol / total_vol;
        inf->mid_volumes[i] = mid_vol / total_vol;
        inf->treble_volumes[i] = treble_vol / total_vol;

        //fprintf(stderr, "%lf %lf %lf    %s\n", inf->bass_volumes[i], inf->mid_volumes[i], inf->treble_volumes[i], name);
    }
    fclose(in);

    return 0;
}

static void zerotrdata(struct training_info *inf) {
    int i;
    inf->n = 0;
    for (i=0; i<Nvols; ++i) {
        inf->bass_volumes[i] = 0;
        inf->mid_volumes[i] = 0;
        inf->treble_volumes[i] = 0;
    }
}

static void train1(const char* prefix, struct training_info *inf)
{
    char buf[50];

    int i;

    for(i=0;; ++i) {
        sprintf(buf, "%s%d.wav", prefix, i);
        struct training_info ti;
        if(get_file_info(buf, &ti)) break;

        ++inf->n;

        int j;
        for (j=0; j<Nvols; ++j) {
            inf->bass_volumes[j]   += ti.bass_volumes[j];
            inf->mid_volumes[j]    += ti.mid_volumes[j];
            inf->treble_volumes[j] += ti.treble_volumes[j];
        }
    }

    int j;
    for (j=0; j<Nvols; ++j) {
        inf->bass_volumes[j]   /= inf->n;
        inf->mid_volumes[j]    /= inf->n;
        inf->treble_volumes[j] /= inf->n;
    }
}

static void print_part(struct training_info *inf, FILE* f) {
    fprintf(f, "%d\n", inf->n);
    int j;
    for (j=0; j<Nvols; ++j) {
        fprintf(f, "%lf %lf %lf\n", inf->bass_volumes[j], inf->mid_volumes[j], inf->treble_volumes[j]);
    }
}

static void train() {
    zerotrdata(&yes);
    zerotrdata(&no);

    fprintf(stderr, "Training...\n");

    train1("train/yes", &yes);
    train1("train/no", &no);

    fprintf(stderr, "Training completed.\n");

    //print_part(&yes, stderr);
    //print_part(&no, stderr);

    int j;
    for (j=0; j<Nvols; ++j) {
        if (yes.bass_volumes[j]   > no.bass_volumes[j]) {   yes.bass_volumes[j] = 1;   no.bass_volumes[j] = 0; }
        if (yes.mid_volumes[j]    > no.mid_volumes[j]) {    yes.mid_volumes[j] = 1;    no.mid_volumes[j] = 0; }
        if (yes.treble_volumes[j] > no.treble_volumes[j]) { yes.treble_volumes[j] = 1; no.treble_volumes[j] = 0; }
    }
}

EOF

set -e

MODEL="ggml-large-v3-turbo-q8_0.bin"
DIR="samples"

for i in $DIR/*.wav; do
	whisper-cli -m $MODEL -otxt -f $i
done

