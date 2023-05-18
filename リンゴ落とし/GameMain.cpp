#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"

void GameMain(int& GameMode) {
	//PlayerInit();								// プレイヤー初期化
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawApple();
	PlayerControl(GameMode);					// プレイヤー操作
	//PlayerFlashing(Count, on, off);					// プレイヤー点滅

}