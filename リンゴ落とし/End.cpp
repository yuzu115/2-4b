#include "DxLib.h"
#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndImg;					// �G���h�摜

int EndWaitTime = 0;			// �҂�����
int PosY;					// �X�N���[�����̂x���W

/****************************************
* �G���h��ʕ`��i�G���h���[���j
*****************************************/
void DrawEnd(int& GameMode)
{
	// �G���h�摜�̕\��
	DrawGraph(0, 0, EndImg, FALSE);

	//�G���f�B���O�\��(��)
	if (++EndWaitTime < 250) PosY = 250 - EndWaitTime;

	SetFontSize(50);
	//DrawFormatString(10, 150, 0x000000, "WaitTime%4d", EndWaitTime);
		
	SetFontSize(40);
	DrawFormatString(100, 310 + PosY, 0x000000, "�f�ޗ��p");
	DrawFormatString(100, 370 + PosY, 0x000000, "�@���炷�Ƃ�");
	//DrawFormatString(100, 410 + PosY, 0x000000, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w");
	
	//�^�C���̉��Z������300f�o�ߌ�I��(��)
	if (EndWaitTime >= 300)
	{
		GameMode = 7;				// CLOSE
	}
}

/****************************************
* �G���h�摜�Ǎ�
*****************************************/
int LoadEndImages(void)
{
	// �G���h�摜�̓Ǎ�
	if ((EndImg = LoadGraph("images/end.png")) == -1) return -1;

	return 0;
}