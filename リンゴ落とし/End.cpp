#include "DxLib.h"
#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndImg;				// �G���h�摜

//int	g_WaitTime = 0;			// �҂�����
//int g_PosY;					// �X�N���[�����̂x���W

/****************************************
* �G���h��ʕ`��i�G���h���[���j
*****************************************/
int DrawEnd(int& GameMode) {

	// �G���h�摜�̓Ǎ�
	if ((EndImg = LoadGraph("images/Back.png")) == -1) return -1;

	// �G���h�摜�̕\��
	DrawGraph(0, 0, EndImg, FALSE);

	//�G���f�B���O�\��
	//if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
	
	SetFontSize(40);
	DrawString(100, 310 , "�f�ޗ��p", 0x000000);
	DrawString(100, 370 , "�@BGM�@�@�@ �@�w�w�w�w", 0x000000);
	DrawString(100, 410 , "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0x000000);

	////�^�C���̉��Z�������I��
	//if (++g_WaitTime > 900)
	//{
	//	GameMode = 8;
	//}
	return 0;
}