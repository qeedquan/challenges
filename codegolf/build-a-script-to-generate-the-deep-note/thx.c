/*

The THX deep note is one of the most recognizable sounds in audio/video production technology. According to its creator, it took about 20,000 lines of C code to generate the final result. We can do better than that.

Your task is to write a script in any language that will generate a sound (to a file or directly to hardware) that fits the trademark description of the THX sound, as provided by the US Patent and Trademark office:

The THX logo theme consists of 30 voices over seven measures, starting in a narrow range, 200 to 400 Hz, and slowly diverting to preselected pitches encompassing three octaves. The 30 voices begin at pitches between 200 Hz and 400 Hz and arrive at pre-selected pitches spanning three octaves by the fourth measure. The highest pitch is slightly detuned while there are double the number of voices of the lowest two pitches.

Note that the "preselected pitches" must be roughly the same as the pitches in the actual THX deep note, which are in the key of E flat.

The shortest code to do so in any language wins.

*/

#include "raylib.h"

int
main(void)
{
	Music music;

	InitAudioDevice();
	music = LoadMusicStream("THX_Deep_Note.mp3");
	PlayMusicStream(music);
	SetTargetFPS(60);
	for (;;) {
		UpdateMusicStream(music);
	}
	UnloadMusicStream(music);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
