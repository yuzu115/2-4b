#include"DxLib.h"
#include"Keyboard.h"

int gBackImg; // �w�i�摜
int gKeyImg;  // �L�[�{�[�h�摜

int LoadImg(void)
{
	// �L�[�{�[�h�摜�̓Ǎ�
	if ((gKeyImg = LoadGraph("images/�^�C�g���Ȃ�.png")) == -1) return -1;
	// �w�i�摜�̓Ǎ�
	if ((gBackImg = LoadGraph("images/�w�i�Q.png")) == -1) return -1;

	return 0;
}

void DrawKeyboard(void)
{
	// �摜�ǂݍ��݊֐����Ăяo��
	LoadImg();

	

	DrawExtendGraph(0, 0, 1280, 720, gBackImg, TRUE);
	DrawExtendGraph(0, 100, 1280, 620, gKeyImg, TRUE);

	DrawString(200, 240, "���O����͂��Ă�������", 0xffffff);
}