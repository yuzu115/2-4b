#include "Help.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int BackImg;		// �w�i�摜

int DrawHelp(void) {

	// �w�i�摜�̓Ǎ�
	if ((BackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// �摜�̕\��
	DrawGraph(0, 0, BackImg, FALSE);

	SetFontSize(40);
	DrawFormatString(500, 10, 0xffffff, "HELP");

	return 0;
}