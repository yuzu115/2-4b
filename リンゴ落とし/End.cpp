#include "DxLib.h"
#include "End.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int EndImg;					// �G���h�摜

//int WaitTime = 0;			// �҂�����
int PosY;					// �X�N���[�����̂x���W

/****************************************
* �G���h��ʕ`��i�G���h���[���j
*****************************************/
void DrawEnd(int& GameMode,int& Count)
{
	LoadEndImages();				// �G���h�摜�Ǎ�

	// �G���h�摜�̕\��
	DrawGraph(0, 0, EndImg, FALSE);

	//�G���f�B���O�\��(��)
	if (++Count < 600) PosY = 300 - Count / 2;

	SetFontSize(30);
	DrawFormatString(0, 0, 0x000000, "Count%4d", Count);
		
	SetFontSize(40);
	DrawFormatString(100, 310 + PosY, 0x000000, "�f�ޗ��p");
	DrawFormatString(100, 370 + PosY, 0x000000, "�@BGM�@�@�@ �@�w�w�w�w");
	DrawFormatString(100, 410 + PosY, 0x000000, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w");

	//�^�C���̉��Z������300f�o�ߌ�I��(��)
	if (++Count >= 300)
	{
		GameMode = 8;				// CLOSE
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