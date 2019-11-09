#include "keys_in_screen.h"

namespace Keyboard_Breaker
{
	namespace Keys
	{
		KEYS keys;

		const float HEIGHT = 40;
		const float WIDTH = 40;

		void Initialice()
		{
			float distanceX = static_cast<float>(GetScreenWidth()) / 4;
			float distanceX2 = static_cast<float>(GetScreenWidth()) / 3.8f;
			float distanceY = static_cast<float>(GetScreenHeight()) / 2.5f;

			float pixelsX = distanceX;
			float pixelsY = distanceY;

			for (int i = 0; i < MAX_KEYS; i++) 
			{
				keys.rec[i].height = HEIGHT;
				keys.rec[i].width = WIDTH;

				keys.rec[i].x = pixelsX;
				keys.rec[i].y = pixelsY;

				pixelsX += keys.rec[i].width + 20;
				
				if ((i == 9) || (i == 19))
				{
					if (i == 19)
					{
						pixelsX = distanceX + keys.rec[i].width + 20;
					}
					else
					{
						pixelsX = distanceX2;
					}
					pixelsY += keys.rec[i].height + 20;
				}

				//keys.none_player; ------------> para agregar las imagenes del artista
				//keys.player1_skin;
				//keys.player2_skin;
			}
		}

		void Draw()
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				DrawRectangleRec(keys.rec[i], WHITE);
			}
		}
	}
}