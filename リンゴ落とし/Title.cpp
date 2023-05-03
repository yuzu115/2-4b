#include "Title.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int TitleImg;			// �^�C�g���摜
int AppleCursorImg;		// �J�[�\���i�ԃ����S�j�摜

int menuNo = 0;		// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEND
int posY;					// �J�[�\����Y���W

/****************************************
* �^�C�g����ʕ`��
*****************************************/
int DrawTitle(int g_KeyFlg,int& GameMode) {

	// �^�C�g���摜�̓Ǎ�
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;
	// �J�[�\���i�ԃ����S�j�摜
	if ((AppleCursorImg = LoadGraph("images/RedApple.png")) == -1) return -1;

	// ���j���[�J�[�\���ړ�����
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++menuNo > 3) menuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--menuNo < 0) menuNo = 3;
	}

	// Z�L�[�Ń��j���[�I��
	if (g_KeyFlg & PAD_INPUT_A) {
		switch (menuNo) {
		//case 0:
		//	GameMode = 1;			// INIT
		//	break;
		case 1:
			GameMode = 3;			// RANKING
			break;
		case 2:
			GameMode = 4;			// HELP
			break;
	 	case 3:
			GameMode = 7;			// END
			break;

		}
	}
	
	// �^�C�g���摜�̕\��
	DrawGraph(0, 0, TitleImg, FALSE);

	// ���j���[�J�[�\���̕\��
	posY = menuNo * 100;

	// �J�[�\���i�ԃ����S�j���k���`��
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
	
	//// ���j���[�J�[�\���i�O�p�`�j�̕\��
	//posY = menuNo * 100;
	//DrawTriangle(810, 325 + posY, 840, 345 + posY, 810, 365 + posY, 0xff0000, TRUE);

	//DrawFormatString(0, 0, 0xffffff, "menuNo %d", menuNo);

	return 0;

}