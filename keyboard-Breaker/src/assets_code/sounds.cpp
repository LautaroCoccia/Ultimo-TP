#include "sounds.h"

namespace Keyboard_Breaker
{
	namespace Sounds
	{
		Music loopMusic;
		Sound key_press;
		Sound mine_press;
		Sound block_press;
		Sound desblock_press;

		void LoadMusic()
		{
			InitAudioDevice();

			loopMusic = LoadMusicStream("assets/loop_songs/main_song.ogg");
			PlayMusicStream(loopMusic);
			
			key_press = LoadSound("assets/efects_sounds/key_press.ogg");
			mine_press = LoadSound("assets/efects_sounds/mine_press.ogg");
			block_press = LoadSound("assets/efects_sounds/block_press.ogg");
			desblock_press = LoadSound("assets/efects_sounds/desblock_press.ogg");
			SetSoundVolume(desblock_press, 0.5f);
		}

		void UpdateGameMusic()
		{
			if (!IsMusicPlaying(loopMusic))
				PlayMusicStream(loopMusic);
			else
				UpdateMusicStream(loopMusic);
		}

		void UnloadMusic_Sound()
		{
			UnloadMusicStream(loopMusic);
			UnloadSound(key_press);
			UnloadSound(mine_press);
			UnloadSound(block_press);
			UnloadSound(desblock_press);

			CloseAudioDevice();
		}
	}
}