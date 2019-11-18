#ifndef POWER_UPS
#define POWER_UPS

#include "players.h"
#include "keys_in_screen.h"

namespace Keyboard_Breaker
{
	namespace Power_Ups
	{
		struct MINE
		{
			bool appear;
			int cont;
		};
		struct COMBOTIME
		{
			bool appear;
			int comboCountP1;
			int comboCountP2;
			int cont;
		};

		extern MINE mine;
		extern COMBOTIME comboTime;

		void InitPowers();
		void Mines();
		void ComboTime();
		void DrawPowers(int i);
	}
}

#endif //POWER_UPS