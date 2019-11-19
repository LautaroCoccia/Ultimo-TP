#ifndef POWER_UPS
#define POWER_UPS

#include "raylib.h"

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
		struct BLOCK_KEY
		{
			Rectangle buttom;
			int ascii;
			bool appear;
			bool activate;
			int desblockPj;
			int contPj;
		};

		extern MINE mine;
		extern COMBOTIME comboTime;
		extern BLOCK_KEY blockKeyPj1;
		extern BLOCK_KEY blockKeyPj2;

		void InitPowers();
		void Mines();
		void ComboTime();
		void BlockKey();
		void DrawPowers(int i);
	}
}

#endif //POWER_UPS