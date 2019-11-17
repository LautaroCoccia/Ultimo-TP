#include "power_ups.h"

namespace Keyboard_Breaker
{
	using namespace Keys;
	using namespace Player;

	namespace Power_Ups
	{
		MINE mine;
		COMBOTIME comboTime;

		const int MINE_DAMEGE = 3;
		const int MAX_CONT_MINE = 10;

		void DrawMines(int i);
		void DrawComboTime();

		void InitPowers()
		{
			mine.appear = false;
			mine.cont = 0;

			comboTime.appear = false;
			comboTime.comboCountP1 = 0;
			comboTime.comboCountP2 = 0;
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
			if (players.pointsPj1 == 5 || players.pointsPj2 == 5)
			{
				comboTime.appear = true;
			}
			else if (comboTime.comboCountP1 == 10 || comboTime.comboCountP2 == 10)
			{
				comboTime.appear = false;
				comboTime.comboCountP1 = 0;
				comboTime.comboCountP2 = 0;
			}

			if (comboTime.appear)
			{
				if (keys.pj1_Point == players.keyPress)
				{
					if (IsKeyPressed(keys.pj1_Point))
					{
						players.pointsPj1++;
						comboTime.comboCountP1++;
					}
				}
				else if (keys.pj2_Point == players.keyPress)
				{
					if (IsKeyPressed(keys.pj2_Point))
					{
						players.pointsPj2++;
						comboTime.comboCountP2++;
					}
				}
			}
		}

		void DrawPowers(int i)
		{
			DrawComboTime();
			DrawMines(i);

			DrawText(FormatText("%i",mine.cont), 400, 10, 40, WHITE);
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
				DrawText("KEYBOARD BREAKER", (GetScreenWidth() / 2) - (MeasureText("KEYBOARD BREAKER", 30) / 2), GetScreenHeight() / 4, 30, RED);
			}
		}

	}
}