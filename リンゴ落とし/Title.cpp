#include "Title.h"

void DrawTitle(void) {

	// �^�C�g���摜�̓Ǎ�
	if ((TitleImg = LoadGraph("images/Title.bmp")) == -1) return -1;

	// �^�C�g���摜�A���j���[�J�[�\���i�O�p�`�j�̕\��
	DrawGraph(0, 0, TitleImg, FALSE);
	posY = menuNo * 45;
	DrawTriangle(140, 210 + posY, 170, 230 + posY, 140, 250 + posY, 0xff0000, TRUE);

}