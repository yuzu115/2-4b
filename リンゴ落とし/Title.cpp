#include "Title.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int TitleImg;			// �^�C�g���摜

static int menuNo = 0;		// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEnd
int posY;					// �J�[�\����Y���W

int DrawTitle(void) {

	// �^�C�g���摜�̓Ǎ�
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;

	// �摜�̕\��
	DrawGraph(0, 0, TitleImg, FALSE);

	// ���j���[�J�[�\���i�O�p�`�j�̕\��
	posY = menuNo * 100;
	DrawTriangle(810, 310 + posY, 840, 330 + posY, 810, 350 + posY, 0xff0000, TRUE);

	return 0;

}