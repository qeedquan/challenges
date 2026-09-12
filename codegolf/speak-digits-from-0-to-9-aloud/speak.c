/*

Inspired by this question from electronics.SE, here's a challenge for you:
https://electronics.stackexchange.com/questions/77227/is-simple-voice-synthesis-just-digits-0-9-possible-with-cortex-m0-with-4kb-fl

Write a program or subroutine that takes in a sequence of decimal digits (0 to 9) and speaks them aloud, without using an existing speech synthesis tool.

Input:
You may ask for the input digits to be provided in any reasonable format, e.g. as a string of ASCII digits, an array of integers, a BCD-encoded number, etc. If your solution is an executable program, you may take the input as a command line parameter, read it from standard input, or obtain it in any other reasonable manner.

Your program must be able to speak at least eight digits per invocation. You may assume that the first digit is not zero, unless it is the only digit.

Output:
Your program may either speak the numbers directly using an audio device, or it may output a playable sound file. The output file, if any, may be in any standard audio format, or it may consist of raw sample data. If you output raw sample data, please note the appropriate parameters for playback (sample rate, bits per sample, endianness, signed/unsigned, # of channels). Formats supported by aplay are preferred.

You are free to decide the details on how the numbers will be spoken, but your output should consist of English language digits spoken in a manner understandable to a typical English speaker, and it should be clear enough for the listener to be able to accurately transcribe a spoken eight-digit random number. No, just beeping n times doesn't count. Don't forget to include pauses between the digits.

Scoring:
Standard code-golf scoring rules apply: Your score is the length of your code in bytes or, if your code is written in Unicode text, in Unicode characters. Lowest score wins. Any language goes.

As the original question on electronics.SE was about embedded programming, I felt it would be appropriate to toss a bone to authors using low-level languages: if your solution is written in a compiled language, you may choose to count the length of the compiled executable file in bytes as your score. (Yes, precompiled bytecode, such as a Java .class file, is OK too.) If you choose to make use of this option, please include a copy of the compiled executable in your answer (e.g. as a hex dump) along with your source code and the compiler version and options you used to generate it.

An honorable mention, along with a +50 rep bounty, will be granted to the first answer that also meets the criteria of the original question, i.e. is capable of running on an embedded MCU with 4 kb of flash and 1 kb of SRAM.

Restrictions:
You may not make use of any files or network resources that are not part of your chosen language's standard runtime environment, unless you count the length of said files or resources as part of your score. (This is to disallow e.g. loading audio samples from the web.)

You may also not use any pre-existing speech synthesis tools or libraries or compilations of audio data (unless you also count their size as part of your score), even if they're included in your chosen language's standard runtime environment.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <SDL3/SDL.h>

typedef struct {
	SDL_AudioSpec spec;
	Uint8 *sound;
	Uint32 soundlen;
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
usage()
{
	fprintf(stderr, "usage: <digits>\n");
	exit(2);
}

void
speak(SDL_AudioStream *stream, wave_t waves[10], const char *text)
{
	SDL_Event ev;
	wave_t *wave;
	int c, r;

	for (; *text; text++) {
		c = *text & 0xff;
		if (!isdigit(c))
			continue;

		wave = &waves[c - '0'];
		r = SDL_PutAudioStreamData(stream, wave->sound, wave->soundlen);
		if (!r)
			printf("audio: %s\n", SDL_GetError());
	}
	SDL_FlushAudioStream(stream);

	for (;;) {
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
			case SDL_EVENT_QUIT:
				SDL_ClearAudioStream(stream);
				break;
			}
		}

		if (SDL_GetAudioStreamQueued(stream) == 0)
			break;

		SDL_Delay(10);
	}
}

int
main(int argc, char *argv[])
{
	SDL_AudioDeviceID id;
	SDL_AudioStream *stream;
	wave_t waves[10];
	wave_t *wave;
	char name[128];
	size_t i;

	if (argc < 2)
		usage();

	if (!SDL_Init(SDL_INIT_AUDIO))
		fatal("Failed to init SDL: %s\n", SDL_GetError());

	for (i = 0; i < SDL_arraysize(waves); i++) {
		wave = &waves[i];
		snprintf(name, sizeof(name), "sounds/%zu.wav", i);
		if (!SDL_LoadWAV(name, &wave->spec, &wave->sound, &wave->soundlen))
			fatal("Failed to load wave file: %s", SDL_GetError());
	}

	wave = &waves[0];
	id = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &wave->spec);
	if (!id)
		fatal("Failed to open audio device: %s", SDL_GetError());

	stream = SDL_CreateAudioStream(&wave->spec, NULL);
	if (!stream)
		fatal("Failed to create audio stream: %s", SDL_GetError());

	if (!SDL_BindAudioStream(id, stream))
		fatal("Failed to bind audio stream: %s", SDL_GetError());

	SDL_ResumeAudioDevice(id);

	speak(stream, waves, argv[1]);

	SDL_Quit();
	return 0;
}
