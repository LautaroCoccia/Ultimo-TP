#include "power_ups.h"

#include "players.h"
#include "keys_in_screen.h"

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

		const int MINE_DAMEGE = 3;
		const int MAX_CONT_MINE = 5;
		const int MAX_CONT_COMBOTIME = 10;
		const int MAX_CONT_BLOCKKEY = 12;
		const int MAX_BLOCKPLAYER = 10;

		const int FONT_COMBO = 50;

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


			blockKeyPj1.buttom = Rectangle{ 70, 70, 60, 40 };
			blockKeyPj1.ascii = KEY_ONE;
			blockKeyPj1.appear = false;
			blockKeyPj1.activate = false;
			blockKeyPj1.contPj = 0;
			blockKeyPj1.desblockPj = 0;

			blockKeyPj2.buttom = Rectangle{ 70, 120, 60, 40 };
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
				}
			}
			else if (blockKeyPj1.ascii == players.keyPress)
			{
				if (blockKeyPj1.appear)
				{
					blockKeyPj1.activate = true;
					blockKeyPj1.appear = false;
				}
			}
			else if (blockKeyPj2.ascii == players.keyPress)
			{
				if (blockKeyPj2.appear)
				{
					blockKeyPj2.activate = true;
					blockKeyPj2.appear = false;
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

			DrawText(FormatText("%i", mine.cont), 400, 10, 40, WHITE);
			DrawText(FormatText("%i", comboTime.cont), 400, 40, 40, GREEN);
		}

		//-------------------------------------------
		// functions for this cpp
		void DrawMines(int i)
		{
			if (mine.cont == MAX_CONT_MINE)
			{
				if (keys.ascii[i] == keys.pj1_Point)
				{
					DrawRectangleRec(keys.rec[i], DARKGREEN);
				}
				else if (keys.ascii[i] == keys.pj2_Point)
				{
					DrawRectangleRec(keys.rec[i], GREEN);
				}
			}
		}

		void DrawComboTime()
		{
			if (comboTime.appear)
			{
				DrawText("KEYBOARD BREAKER", (GetScreenWidth() / 2) - (MeasureText("KEYBOARD BREAKER", FONT_COMBO) / 2), GetScreenHeight() / 4, FONT_COMBO, RED);
			}
		}

		void DrawBlockKey()
		{
			if (blockKeyPj1.activate)
			{
				DrawText(FormatText("%i", blockKeyPj2.desblockPj), 400, 600, 40, RED);
			}
			else
			{
				DrawText(FormatText("%i", blockKeyPj2.contPj), 400, 600, 40, WHITE);
			}

			if (blockKeyPj2.activate)
			{
				DrawText(FormatText("%i", blockKeyPj1.desblockPj), 400, 650, 40, BLUE);
			}
			else
			{
				DrawText(FormatText("%i", blockKeyPj1.contPj), 400, 650, 40, WHITE);
			}

			if (blockKeyPj1.appear)
			{
				DrawRectangleRec(blockKeyPj1.buttom, BLUE);
			}
			if (blockKeyPj2.appear)
			{
				DrawRectangleRec(blockKeyPj2.buttom, RED);
			}
		}

	}
}