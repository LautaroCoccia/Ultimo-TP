#include "power_ups.h"

#include "players.h"
#include "keys_in_screen.h"
#include "assets_code/sounds.h"

namespace Keyboard_Breaker
{
	using namespace Keys;
	using namespace Player;

	namespace Power_Ups
	{
		MINE mine;
		COMBOTIME comboTime;
		BLOCK_KEY blockKeyPj1;
		BLOCK_KEY blockKeyPj2;

		const int MINE_DAMEGE = 6;
		const int MAX_CONT_MINE = 5;
		const int MAX_CONT_COMBOTIME = 10;
		const int MAX_CONT_BLOCKKEY = 12;
		const int MAX_BLOCKPLAYER = 10;

		const float HEIGHT = 40;
		const float WIDTH = 40;
		const float DISTANCE = 20;

		const int FONT_TITLE = 70;
		const int FONT_KEYS = 20;

		void DrawMines(int i);
		void DrawComboTime();
		void DrawBlockKey();

		void InitPowers()
		{
			mine.appear = false;
			mine.cont = 0;


			comboTime.appear = false;
			comboTime.comboCountP1 = 0;
			comboTime.comboCountP2 = 0;
			comboTime.cont = 0;


			float distanceX = static_cast<float>((GetScreenWidth()) / 4) - (WIDTH / 2);
			float distanceY = static_cast<float>(GetScreenHeight()) / 2.5f - HEIGHT - DISTANCE;

			blockKeyPj1.buttom = Rectangle{ distanceX, distanceY, HEIGHT, WIDTH };
			blockKeyPj1.ascii = KEY_ONE;
			blockKeyPj1.appear = false;
			blockKeyPj1.activate = false;
			blockKeyPj1.contPj = 0;
			blockKeyPj1.desblockPj = 0;

			distanceX = 810;
			distanceY = static_cast<float>(GetScreenHeight()) / 2.5f - HEIGHT - DISTANCE;

			blockKeyPj2.buttom = Rectangle{ distanceX, distanceY, HEIGHT, WIDTH };
			blockKeyPj2.ascii = KEY_ZERO;
			blockKeyPj2.appear = false;
			blockKeyPj2.activate = false;
			blockKeyPj2.contPj = 0;
			blockKeyPj2.desblockPj = 0;
		}
		void Mines()
		{
			if (mine.cont >= MAX_CONT_MINE)
			{
				mine.appear = true;
				mine.cont = 0;
			}

			if (keys.pj1_Point == players.keyPress)
			{
				if (mine.appear)
				{
					players.pointsPj1 -= MINE_DAMEGE;
					mine.appear = false;
					PlaySound(Sounds::mine_press);
				}
				else
				{
					mine.cont++;
				}
			}
			else if (keys.pj2_Point == players.keyPress)
			{
				if (mine.appear)
				{
					players.pointsPj2 -= MINE_DAMEGE;
					mine.appear = false;
					PlaySound(Sounds::mine_press);
				}
				else
				{
					mine.cont++;
				}
			}
		}

		void ComboTime()
		{
			if (comboTime.cont >= MAX_CONT_COMBOTIME)
			{
				comboTime.appear = true;
				comboTime.cont = 0;
			}
			else if (comboTime.appear == true && (comboTime.comboCountP1 >= 10 || comboTime.comboCountP2 >= 10))
			{
				comboTime.appear = false;
				comboTime.comboCountP1 = 0;
				comboTime.comboCountP2 = 0;
			}

			if (keys.pj1_Point == players.keyPress)
			{
				if (comboTime.appear)
				{
					players.pointsPj1++;
					comboTime.comboCountP1++;
					PlaySound(Sounds::key_press);
				}
				else
				{
					comboTime.cont++;
				}
			}
			else if (keys.pj2_Point == players.keyPress)
			{
				if (comboTime.appear)
				{
					players.pointsPj2++;
					comboTime.comboCountP2++;
					PlaySound(Sounds::key_press);
				}
				else
				{
					comboTime.cont++;
				}
			}
		}

		void BlockKey()
		{
			if (blockKeyPj1.contPj >= MAX_CONT_BLOCKKEY)
			{
				blockKeyPj1.appear = true;
				blockKeyPj1.activate = false;
				blockKeyPj1.contPj = 0;
				blockKeyPj2.desblockPj = 0;
			}
			if (blockKeyPj2.contPj >= MAX_CONT_BLOCKKEY)
			{
				blockKeyPj2.appear = true;
				blockKeyPj2.activate = false;
				blockKeyPj2.contPj = 0;
				blockKeyPj1.desblockPj = 0;
			}


			if (keys.pj1_Point == players.keyPress)
			{
				if (!blockKeyPj1.appear && !blockKeyPj2.activate && !comboTime.appear)
				{
					blockKeyPj1.contPj++;
				}
				else if (blockKeyPj2.activate)
				{
					blockKeyPj1.desblockPj++;
					PlaySound(Sounds::desblock_press);
				}
			}
			else if (keys.pj2_Point == players.keyPress)
			{
				if (!blockKeyPj2.appear && !blockKeyPj1.activate && !comboTime.appear)
				{
					blockKeyPj2.contPj++;
				}
				else if (blockKeyPj1.activate)
				{
					blockKeyPj2.desblockPj++; 
					PlaySound(Sounds::desblock_press);
				}
			}
			else if (blockKeyPj1.ascii == players.keyPress)
			{
				if (blockKeyPj1.appear)
				{
					blockKeyPj1.activate = true;
					blockKeyPj1.appear = false;
					PlaySound(Sounds::block_press);
				}
			}
			else if (blockKeyPj2.ascii == players.keyPress)
			{
				if (blockKeyPj2.appear)
				{
					blockKeyPj2.activate = true;
					blockKeyPj2.appear = false;
					PlaySound(Sounds::block_press);
				}
			}


			if (blockKeyPj1.desblockPj >= MAX_BLOCKPLAYER)
			{
				blockKeyPj2.activate = false;

				blockKeyPj1.contPj = 0;
				blockKeyPj1.desblockPj = 0;
			}
			if (blockKeyPj2.desblockPj >= MAX_BLOCKPLAYER)
			{
				blockKeyPj1.activate = false;

				blockKeyPj2.contPj = 0;
				blockKeyPj2.desblockPj = 0;
			}
		}

		void DrawPowers(int i)
		{
			DrawMines(i);
			DrawComboTime();
			DrawBlockKey();
		}

		//-------------------------------------------
		// functions for this cpp
		void DrawMines(int i)
		{
			if (mine.cont == MAX_CONT_MINE)
			{
				if (keys.ascii[i] == keys.pj1_Point)
				{
					DrawRectangleRec(keys.rec[i], BLUE);
					DrawRectangleLinesEx(keys.rec[i], 6, GREEN);
					
				}
				else if (keys.ascii[i] == keys.pj2_Point)
				{
					DrawRectangleRec(keys.rec[i], RED);
					DrawRectangleLinesEx(keys.rec[i], 6, GREEN);
				}
				
				DrawText("MINES!!", ((GetScreenWidth() / 2) - (MeasureText("MINES!!", FONT_TITLE) / 2)), (GetScreenHeight() / 2 + GetScreenHeight() / 4), FONT_TITLE, GREEN);
			}
		}

		void DrawComboTime()
		{
			if (comboTime.appear)
			{
				DrawText("KEYBOARD BREAKER", (GetScreenWidth() / 2) - (MeasureText("KEYBOARD BREAKER", FONT_TITLE) / 2), GetScreenHeight() / 4, FONT_TITLE, RED);
			}
		}

		void DrawBlockKey()
		{
			if (blockKeyPj1.appear)
			{
				DrawRectangleRec(blockKeyPj1.buttom, BLUE);
				DrawText("1", static_cast<int>((blockKeyPj1.buttom.x + blockKeyPj1.buttom.width / 2) - (MeasureText("1", FONT_KEYS) / 2)), static_cast<int>(blockKeyPj1.buttom.y + 10), FONT_KEYS, BLACK);
			}
			if (blockKeyPj2.appear)
			{
				DrawRectangleRec(blockKeyPj2.buttom, RED);
				DrawText("0", static_cast<int>((blockKeyPj2.buttom.x + blockKeyPj2.buttom.width / 2) - (MeasureText("0", FONT_KEYS) / 2)), static_cast<int>(blockKeyPj2.buttom.y + 10), FONT_KEYS, BLACK);
			}
		}

	}
}