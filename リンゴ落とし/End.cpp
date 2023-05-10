#include "DxLib.h"
#include "infomation.h"
#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndImg;				// �G���h�摜

int WaitTime = 0;			// �҂�����
int PosY;					// �X�N���[�����̂x���W

/****************************************
* �G���h��ʕ`��i�G���h���[���j
*****************************************/
int DrawEnd(void)
{
	// �G���h�摜�̓Ǎ�
	if ((EndImg = LoadGraph("images/Back.png")) == -1) return -1;

	// �G���h�摜�̕\��
	DrawGraph(0, 0, EndImg, FALSE);

	//�G���f�B���O�\��(��)
	if (++WaitTime < 600) PosY = 300 - WaitTime / 2;

	SetFontSize(30);
	DrawFormatString(0, 0, 0x000000, "WaitTime%4d", WaitTime);

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
		
	SetFontSize(40);
	DrawFormatString(100, 310 + PosY, 0x000000, "�f�ޗ��p");
	DrawFormatString(100, 370 + PosY, 0x000000, "�@BGM�@�@�@ �@�w�w�w�w");
	DrawFormatString(100, 410 + PosY, 0x000000, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w");

	//�^�C���̉��Z������300f�o�ߌ�I��(��)
	if (++WaitTime > 900)
	{
		GameMode = 8;				// CLOSE
	}

	return 0;
}