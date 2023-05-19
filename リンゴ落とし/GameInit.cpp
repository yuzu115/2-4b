#include "DxLib.h"
#include "GameInit.h"
#include "Player.h"

/*****************************************
*　ゲーム初期化
******************************************/
void GameInit(int& GameMode)
{
	PlayerInit();				// プレイヤー初期化

	GameMode = 2;				// MAIN
}