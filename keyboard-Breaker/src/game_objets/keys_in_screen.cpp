#include "keys_in_screen.h"

#include "players.h"
#include "game_screens/gameplay.h"
#include "game_objets/power_ups.h"
#include "assets_code/sounds.h"

namespace Keyboard_Breaker
{
	using namespace Player;
	using namespace Gameplay;
	using namespace Power_Ups;

	namespace Keys
	{
		KEYS keys;
		FIGHT_BAR fightBar;

		const float HEIGHT = 40;
		const float WIDTH = 40;
		const float DISTANCE = 20;
		const int FONT_KEYS = 20;

		int MovePoint(int move_point, int static_point);
		void DeclarateKeys();

		void Initialice()
		{
			float distanceX = static_cast<float>(GetScreenWidth()) / 4;
			float distanceX2 = static_cast<float>(GetScreenWidth()) / 3.8f;
			float distanceY = static_cast<float>(GetScreenHeight()) / 2.5f;

			float pixelsX = distanceX;
			float pixelsY = distanceY;

			comboTime.appear = false;
			comboTime.comboCountP1 = 0;
			comboTime.comboCountP2 = 0;

			DeclarateKeys();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				keys.rec[i].height = HEIGHT;
				keys.rec[i].width = WIDTH;
				keys.rec[i].x = pixelsX;
				keys.rec[i].y = pixelsY;

				pixelsX += keys.rec[i].width + DISTANCE;

				if ((i == 9) || (i == 18))
				{
					if (i == 18)
					{
						pixelsX = distanceX + keys.rec[i].width + DISTANCE;
					}
					else
					{
						pixelsX = distanceX2;
					}
					pixelsY += keys.rec[i].height + DISTANCE;
				}

				keys.pj1_Point = MovePoint(keys.pj1_Point, keys.pj2_Point);
				keys.pj2_Point = MovePoint(keys.pj2_Point, keys.pj1_Point);
			}
		}

		void EarnPoint()
		{
			switch (modes)
			{
			case normal:
				if (keys.pj1_Point == players.keyPress || blockKeyPj1.ascii == players.keyPress)
				{
					BlockKey();

					if (!blockKeyPj2.activate)
					{
						ComboTime();
						if (!comboTime.appear)
						{
							Mines();
							players.pointsPj1++;
							PlaySound(Sounds::key_press);
						}
						players.keyPress = 0;
						keys.pj1_Point = MovePoint(keys.pj1_Point, keys.pj2_Point);
					}
				}
				else if (keys.pj2_Point == players.keyPress || blockKeyPj2.ascii == players.keyPress)
				{
					BlockKey();

					if (!blockKeyPj1.activate)
					{
						ComboTime();
						if (!comboTime.appear)
						{
							Mines();
							players.pointsPj2++;
							PlaySound(Sounds::key_press);
						}
						players.keyPress = 0;
						keys.pj2_Point = MovePoint(keys.pj2_Point, keys.pj1_Point);
					}
				}
				break;
			case fight:
				if (keys.pj1_Point == players.keyPress)
				{
					pointsBar.rec.x += pointsBar.movement;
					players.keyPress = 0;
					keys.pj1_Point = MovePoint(keys.pj1_Point, keys.pj2_Point);
					PlaySound(Sounds::key_press);
				}
				else if (keys.pj2_Point == players.keyPress)
				{
					pointsBar.rec.x -= pointsBar.movement;
					players.keyPress = 0;
					keys.pj2_Point = MovePoint(keys.pj2_Point, keys.pj1_Point);
					PlaySound(Sounds::key_press);
				}
				break;
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

				DrawPowers(i);

				char example[2] = { keys.drawKey[i], '\0' };
				DrawText(example, static_cast<int>((keys.rec[i].x + keys.rec[i].width / 2) - (MeasureText(example, FONT_KEYS) / 2)), static_cast<int>(keys.rec[i].y + 10), FONT_KEYS, BLACK);
			}
		}

		// ---------------------------------------------------------------------------------------- \\
		// functions for this cpp
		int MovePoint(int move_point, int static_point)
		{
			if (!comboTime.appear)
			{
				move_point = static_point;

				while (move_point == static_point)
				{
					move_point = GetRandomValue(KEY_A, KEY_Z);
				}
			}
			return move_point;
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