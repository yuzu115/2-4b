#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndBackImg;			// �w�i�摜

/****************************************
* �G���h��ʕ`��
*****************************************/
int DrawEnd(void) {

	// �w�i�摜�̓Ǎ�
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// �摜�̕\��
	DrawGraph(0, 0, EndBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(500, 10, 0xffffff, "END");

}