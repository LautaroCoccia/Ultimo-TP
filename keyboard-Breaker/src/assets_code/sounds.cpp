#include "sounds.h"

namespace Keyboard_Breaker
{
	namespace Sounds
	{
		Music loopMusic;
		Sound key_press;
		Sound mine_press;

		bool muteSound;

		void LoadMusic()
		{
			InitAudioDevice();

			loopMusic = LoadMusicStream("loop_songs/main_song.ogg");
			PlayMusicStream(loopMusic);
			
			key_press = LoadSound("efects_sounds/key_press.wav");
			mine_press = LoadSound("efects_sounds/mine_press.wav");

			//muteSound = false;
		}

		void UpdateGameMusic()
		{
			if (!IsMusicPlaying(loopMusic))
				PlayMusicStream(loopMusic);
			else
				UpdateMusicStream(loopMusic);

			/*if (InputMuteSound())
			{
				muteSound = !muteSound;
			}*/

			/*if (muteSound == true)
			{
				PauseMusicStream(loopMusic);
				SetSoundVolume(key_press, 0.0f);
				SetSoundVolume(mine_press, 0.0f);
			}
			else
			{
				ResumeMusicStream(loopMusic);
				SetSoundVolume(key_press, 1.0f);
				SetSoundVolume(mine_press, 1.0f);
			}*/
		}

		void UnloadMusic_Sound()
		{
			UnloadMusicStream(loopMusic);
			UnloadSound(key_press);
			UnloadSound(mine_press);

			CloseAudioDevice();
		}
	}
}