#include <stdlib.h>
#include <time.h>

#include "keys_in_screen.h"

#include "players.h"


namespace Keyboard_Breaker
{
	using namespace Player;

	namespace Keys
	{
		KEYS keys;

		const float HEIGHT = 40;
		const float WIDTH = 40;

		void DeclarateKeys();

		void Initialice()
		{
			float distanceX = static_cast<float>(GetScreenWidth()) / 4;
			float distanceX2 = static_cast<float>(GetScreenWidth()) / 3.8f;
			float distanceY = static_cast<float>(GetScreenHeight()) / 2.5f;

			float pixelsX = distanceX;
			float pixelsY = distanceY;

			DeclarateKeys();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				keys.rec[i].height = HEIGHT;
				keys.rec[i].width = WIDTH;
				keys.rec[i].x = pixelsX;
				keys.rec[i].y = pixelsY;

				pixelsX += keys.rec[i].width + 20;

				if ((i == 9) || (i == 18))
				{
					if (i == 18)
					{
						pixelsX = distanceX + keys.rec[i].width + 20;
					}
					else
					{
						pixelsX = distanceX2;
					}
					pixelsY += keys.rec[i].height + 20;
				}

				MovePoint();
				//keys.none_player; ------------> para agregar las imagenes del artista
				//keys.player_skin;
				//keys.player2_skin;
			}
		}

		void MovePoint()
		{
			keys.pj1_Point = keys.pj2_Point;
			while (keys.pj1_Point == keys.pj2_Point)
			{
				keys.pj1_Point = GetRandomValue(KEY_A, KEY_Z);
				keys.pj2_Point = GetRandomValue(KEY_A, KEY_Z);
			}
		}

		void EarnPoint()
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				if (keys.pj1_Point == players.keyPress)
				{
					players.pointsPj1++;
					players.keyPress = 0;
					MovePoint();
				}
				else if (keys.pj2_Point == players.keyPress)
				{
					players.pointsPj2++;
					players.keyPress = 0;
					MovePoint();
				}
			}
		}

		void Draw()
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				if (keys.ascii[i] == keys.pj1_Point)
				{
					DrawRectangleRec(keys.rec[i], BLUE);
				}
				else if (keys.ascii[i] == keys.pj2_Point)
				{
					DrawRectangleRec(keys.rec[i], RED);
				}
				else
				{
					DrawRectangleRec(keys.rec[i], WHITE);
				}

				DrawText(&keys.drawKey[i], static_cast<int>(keys.rec[i].x + 10), static_cast<int>(keys.rec[i].y + 10), 20, BLACK);
			}
		}

		void DeclarateKeys()
		{
			keys.ascii[0] = KEY_Q;
			keys.drawKey[0] = 'Q';

			keys.ascii[1] = KEY_W;
			keys.drawKey[1] = 'W';

			keys.ascii[2] = KEY_E;
			keys.drawKey[2] = 'E';

			keys.ascii[3] = KEY_R;
			keys.drawKey[3] = 'R';

			keys.ascii[4] = KEY_T;
			keys.drawKey[4] = 'T';

			keys.ascii[5] = KEY_Y;
			keys.drawKey[5] = 'Y';

			keys.ascii[6] = KEY_U;
			keys.drawKey[6] = 'U';

			keys.ascii[7] = KEY_I;
			keys.drawKey[7] = 'I';

			keys.ascii[8] = KEY_O;
			keys.drawKey[8] = 'O';

			keys.ascii[9] = KEY_P;
			keys.drawKey[9] = 'P';

			keys.ascii[10] = KEY_A;
			keys.drawKey[10] = 'A';

			keys.ascii[11] = KEY_S;
			keys.drawKey[11] = 'S';

			keys.ascii[12] = KEY_D;
			keys.drawKey[12] = 'D';

			keys.ascii[13] = KEY_F;
			keys.drawKey[13] = 'F';

			keys.ascii[14] = KEY_G;
			keys.drawKey[14] = 'G';

			keys.ascii[15] = KEY_H;
			keys.drawKey[15] = 'H';

			keys.ascii[16] = KEY_J;
			keys.drawKey[16] = 'J';

			keys.ascii[17] = KEY_K;
			keys.drawKey[17] = 'K';

			keys.ascii[18] = KEY_L;
			keys.drawKey[18] = 'L';
			/*
			keys.ascii[0] = KEY_Ñ;
			keys.drawKey[0] = 'Ñ';
			*/
			keys.ascii[19] = KEY_Z;
			keys.drawKey[19] = 'Z';

			keys.ascii[20] = KEY_X;
			keys.drawKey[20] = 'X';

			keys.ascii[21] = KEY_C;
			keys.drawKey[21] = 'C';

			keys.ascii[22] = KEY_V;
			keys.drawKey[22] = 'V';

			keys.ascii[23] = KEY_B;
			keys.drawKey[23] = 'B';

			keys.ascii[24] = KEY_N;
			keys.drawKey[24] = 'N';

			keys.ascii[25] = KEY_M;
			keys.drawKey[25] = 'M';
		}
	}
}