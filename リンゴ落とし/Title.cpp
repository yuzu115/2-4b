#include "Title.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int TitleImg;			// �^�C�g���摜

static int menuNo = 0;		// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEnd
int posY;					// �J�[�\����Y���W

int DrawTitle(int g_KeyFlg) {

	// �^�C�g���摜�̓Ǎ�
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;

	// ���j���[�J�[�\���ړ�����
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++menuNo > 3) menuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--menuNo < 0) menuNo = 3;
	}


	// Z�L�[�Ń��j���[�I��
	//if (g_KeyFlg & PAD_INPUT_A) {
	//	switch (menuNo) {
	//	case 0:
	//		GameMode = INIT;
	//		break;
	//	case 1:
	//		GameMode = RANKING;
	//		break;
	//	case 2:
	//		GameMode = HELP;
	//		break;
 //		case 3:
	//		GameMode = END;
	//		break;

	//	}
	//}


	// �摜�̕\��
	DrawGraph(0, 0, TitleImg, FALSE);

	// ���j���[�J�[�\���i�O�p�`�j�̕\��
	posY = menuNo * 100;
	DrawTriangle(810, 310 + posY, 840, 330 + posY, 810, 350 + posY, 0xff0000, TRUE);

	return 0;

}