#include "DxLib.h"
#include "GameInit.h"
#include "Player.h"

/*****************************************
*�@�Q�[��������
******************************************/
void GameInit(int& GameMode)
{
	PlayerInit();				// �v���C���[������

	GameMode = 2;				// MAIN
}