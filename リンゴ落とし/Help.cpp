#include "Help.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int HelpBackImg;		// �w�i�摜

int DrawHelp(void) {

	// �w�i�摜�̓Ǎ�
	if ((HelpBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// �摜�̕\��
	DrawGraph(0, 0, HelpBackImg, FALSE);

	SetFontSize(40);
	DrawFormatString(500, 10, 0xffffff, "HELP");

	return 0;
}