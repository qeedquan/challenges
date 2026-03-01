/*

Introduction
Some days ago I needed a metronome for something. I had none available so I downloaded an app from the App Store. The app had a size of 71 MB!!!
71 MB for making tic-toc...?!
So code-golf came into my mind and I was wondering if some of you guys could improve this.

Challenge
Golf some code that outputs some sound. It's pretty irrelevant what kind of sound. If required create some sound file... but a System beep will do the job as well. (Here is some sound I created... nothing special.)

Input: The beats per minute the metronome outputs.

Example
This is a non-golfed Java-version! It's just to show you the task.

public class Metronome {
  public static void main(String[] args) throws InterruptedException {
    int bpm = Integer.valueOf(args[0]);
    int interval = 60000 / bpm;

    while(true) {
        java.awt.Toolkit.getDefaultToolkit().beep();
        // or start playing the sound
        Thread.sleep(interval);
        System.out.println("Beep!");

    }
  }
}
Rules
You may not use external libaries, only tools of the language itself are allowed.
Only the bytes of the source code count... not the sound file.

This is code-golf, so the submission with the least amount of bytes wins!

EDIT:
Example output: So something like this would be the output for 120 bps: link
https://www.mediafire.com/file/5d12f62gvzn2p92

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <SDL3/SDL.h>

typedef unsigned long long uvlong;

typedef struct {
	SDL_AudioDeviceID id;
	SDL_AudioSpec spec;
	SDL_AudioStream *stream;
	Uint8 *sound;
	Uint32 soundlen;
	int interval;
} wave_t;

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
usage(void)
{
	fprintf(stderr, "usage: sound.wav bpm\n");
	exit(2);
}

void
initsdl(void)
{
	if (!SDL_Init(SDL_INIT_AUDIO))
		fatal("Failed to init SDL: %s\n", SDL_GetError());
}

void
play(wave_t *wave)
{
	int r;

	r = SDL_PutAudioStreamData(wave->stream, wave->sound, wave->soundlen);
	if (!r)
		printf("audio: %s\n", SDL_GetError());
}

int
main(int argc, char *argv[])
{
	SDL_Event ev;
	wave_t wave;
	uvlong tick;
	int bpm;

	if (argc != 3)
		usage();

	bpm = atoi(argv[2]);
	if (bpm < 1)
		bpm = 120;

	wave.interval = 60000 / bpm;

	initsdl();
	if (!SDL_LoadWAV(argv[1], &wave.spec, &wave.sound, &wave.soundlen))
		fatal("Failed to load wave file: %s", SDL_GetError());

	wave.id = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &wave.spec);
	if (!wave.id)
		fatal("Failed to open audio device: %s", SDL_GetError());

	wave.stream = SDL_CreateAudioStream(&wave.spec, NULL);
	if (!wave.stream)
		fatal("Failed to create audio stream: %s", SDL_GetError());

	if (!SDL_BindAudioStream(wave.id, wave.stream))
		fatal("Failed to bind audio stream: %s", SDL_GetError());

	SDL_ResumeAudioDevice(wave.id);

	tick = 0;
	for (;;) {
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
			case SDL_EVENT_QUIT:
				goto out;
			}
		}

		printf("BPM: %d: %llu\n", bpm, tick++);
		fflush(stdout);
		play(&wave);
		SDL_Delay(wave.interval);
	}

out:
	SDL_Quit();
	return 0;
}
