#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"

void GameMain(int& GameMode) {
	//PlayerInit();								// �v���C���[������
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawApple();
	PlayerControl(GameMode);					// �v���C���[����
	//PlayerFlashing(Count, on, off);					// �v���C���[�_��

}