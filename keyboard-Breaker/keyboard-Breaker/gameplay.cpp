#include "gameplay.h"
#include "raylib.h"
static bool gameplay = false;

void SetGameplayActive()
{
	gameplay = !gameplay;
}
bool GetGameplay()
{
	return gameplay;
}
void UpdateGameplay()
{
	DrawText("Playing ", static_cast<int>(GetScreenWidth() / 2.5), GetScreenHeight() / 5, 30, WHITE);

}

