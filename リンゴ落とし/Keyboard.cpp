#include"DxLib.h"
#include"Keyboard.h"

int gBackImg; // �w�i�摜
int gKeyImg[4];  // �L�[�{�[�h�摜

int LoadImg(void)
{
	// �L�[�{�[�h�摜�̓Ǎ�
	if ((gKeyImg[0] = LoadGraph("images/�L�[�{�[�h.png")) == -1) return -1;
	// �w�i�摜�̓Ǎ�
	if ((gBackImg = LoadGraph("images/backname.png")) == -1) return -1;

	return 0;
}

void DrawKeyboard(void)
{
	// �摜�ǂݍ��݊֐����Ăяo��
	LoadImg();

	// �w�i�摜�̕\��
	DrawExtendGraph(0, 0,1280,720,gBackImg, TRUE);
	// �L�[�{�[�h�摜�̕\��
	DrawExtendGraph(200,230,1090,690 ,gKeyImg[0], TRUE);

	//DrawString(200, 240, "���O����͂��Ă�������", 0xffffff);
}