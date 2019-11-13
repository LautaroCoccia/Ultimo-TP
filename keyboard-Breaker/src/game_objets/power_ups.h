#ifndef POWER_UPS
#define POWER_UPS

namespace Keyboard_Breaker
{

	namespace Power_Ups
	{
		struct MINE
		{
			bool activateInGame;
			bool appear;
		};
		struct COMBOTIME
		{
			bool appear;
			int comboCountP1;
			int comboCountP2;
		};

		extern MINE mine;
		extern COMBOTIME comboTime;

	}
}

#endif //POWER_UPS