/*

Given an audio file, determine whether it is encoded in a lossy format or a lossless format. For the purposes of this challenge, only the following formats need to be classified:

Lossy
AC3
AMR
AAC
MP2
MP3
Ogg Vorbis
WMA

Lossless
AIFF
FLAC
TTA
WAV

Rules
If input is taken in the form of a filename, no assumptions should be made about the filename (e.g. the extension is not guaranteed to be correct for the format, or even present).
There will be no ID3 or APEv2 metadata present in input files.
Any two unique and distinguishable outputs may be used, such as 0 and 1, lossy and lossless, foo and bar, etc.
Test Cases
The test cases for this challenge consist of a zip file located here which contains two directories: lossy and lossless. Each directory contains several audio files that are all 0.5-second 440 Hz sine waves, encoded in various formats. All of the audio files have extensions matching the formats above, with the exception of A440.m4a (which is AAC audio in a MPEG Layer 4 container).

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
match(const uint16_t *magic, size_t nmagic, const uint8_t *buf, size_t len)
{
	size_t i;

	if (len < nmagic)
		return 0;

	for (i = 0; i < nmagic; i++) {
		if (magic[i] > 0xff)
			continue;

		if (magic[i] != buf[i])
			return 0;
	}

	return 1;
}

const char *
classify(const char *name)
{
	static const uint16_t ac3[] = {0x0B, 0x77};
	static const uint16_t amr[] = {0x23, 0x21, 0x41, 0x4D, 0x52};
	static const uint16_t mp2[] = {0xFF, 0xFD};
	static const uint16_t mp3[] = {0xFF, 0xFB};
	static const uint16_t ogg[] = {0x4F, 0x67, 0x67, 0x53};
	static const uint16_t wma[] = {0x30, 0x26, 0xB2, 0x75, 0x8E, 0x66, 0xCF, 0x11, 0xA6, 0xD9, 0x00, 0xAA, 0x00, 0x62, 0xCE, 0x6C};
	static const uint16_t aiff[] = {0x46, 0x4F, 0x52, 0x4D, 0x100, 0x100, 0x100, 0x100, 0x41, 0x49, 0x46, 0x46};
	static const uint16_t flac[] = {0x66, 0x4C, 0x61, 0x43};
	static const uint16_t tta[] = {0x54, 0x54, 0x41, 0x31};
	static const uint16_t wav[] = {0x52, 0x49, 0x46, 0x46, 0x100, 0x100, 0x100, 0x100, 0x57, 0x41, 0x56, 0x45};

	static const struct Format {
		const uint16_t *magic;
		size_t nmagic;
		const char *type;
	} fmts[] = {
	    {ac3, nelem(ac3), "lossy"},
	    {amr, nelem(amr), "lossy"},
	    {mp2, nelem(mp2), "lossy"},
	    {mp3, nelem(mp3), "lossy"},
	    {ogg, nelem(ogg), "lossy"},
	    {wma, nelem(wma), "lossy"},
	    {aiff, nelem(aiff), "lossless"},
	    {flac, nelem(flac), "lossless"},
	    {tta, nelem(tta), "lossless"},
	    {wav, nelem(wav), "lossless"},
	};

	const struct Format *f;
	const char *ret;
	FILE *fp;
	uint8_t buf[0x20];
	size_t len;
	size_t i;

	fp = fopen(name, "rb");
	if (!fp)
		return "error";

	ret = "unknown";
	len = fread(buf, 1, sizeof(buf), fp);
	for (i = 0; i < nelem(fmts); i++) {
		f = fmts + i;
		if (match(f->magic, f->nmagic, buf, len)) {
			ret = f->type;
			break;
		}
	}

	fclose(fp);
	return ret;
}

void
usage(void)
{
	fprintf(stderr, "usage: <file>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
		usage();

	printf("%s\n", classify(argv[1]));
	return 0;
}
