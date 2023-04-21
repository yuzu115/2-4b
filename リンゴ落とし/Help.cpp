#include "Help.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int HelpBackImg;		// �w�i�摜

/****************************************
* �w���v��ʕ`��
*****************************************/
int DrawHelp(int g_KeyFlg,int& GameMode) {

	// �w�i�摜�̓Ǎ�
	if ((HelpBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// A�{�^���Ń^�C�g����
	if (g_KeyFlg & PAD_INPUT_A) {
		GameMode = 0;					// �^�C�g����ʂ�
	}
	// B�{�^���ŃQ�[���X�^�[�g
	if (g_KeyFlg & PAD_INPUT_B) {
		//GameMode = 1;					// �Q�[���X�^�[�g��
		GameMode = 7;					// �G���h��
	}

	// �摜�̕\��
	DrawGraph(0, 0, HelpBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(450, 100, 0x000000, "�������");

	SetFontSize(70);
	DrawFormatString(100, 310, 0x000000, "���X�e�B�b�N  ���E�ړ�");
	DrawFormatString(100, 410, 0x000000, "START�{�^���@ �|�[�Y/�|�[�Y����");

	SetFontSize(30);
	DrawFormatString(400, 650, 0x000000, "A�F�^�C�g��");
	DrawFormatString(800, 650, 0x000000, "B�F�G���h");

	return 0;
}