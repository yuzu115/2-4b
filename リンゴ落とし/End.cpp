#include "DxLib.h"
#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndBackImg;				// �w�i�摜

int WaitTime = 0;			// �҂�����
int PosY;					// �X�N���[�����̂x���W

/****************************************
* �G���h��ʕ`��i�G���h���[���j
*****************************************/
void DrawEnd(int& GameMode)
{
	LoadEndImages();				// �G���h�摜�Ǎ�

	// �G���h�摜�̕\��
	DrawGraph(0, 0, EndBackImg, FALSE);

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

}

/****************************************
* �G���h�摜�Ǎ�
*****************************************/
int LoadEndImages(void)
{
	// �w�i�摜�̓Ǎ�
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}