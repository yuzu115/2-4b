#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndBackImg;			// �w�i�摜

/****************************************
* �G���h��ʕ`��i�G���h���[���j
*****************************************/
int DrawEnd(void) {

	// �w�i�摜�̓Ǎ�
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// �摜�̕\��
	DrawGraph(0, 0, EndBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
	
	SetFontSize(40);
	DrawString(100, 310 , "�f�ޗ��p", 0x000000);
	DrawString(100, 370 , "�@BGM�@�@�@ �@�w�w�w�w", 0x000000);
	DrawString(100, 410 , "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0x000000);

}