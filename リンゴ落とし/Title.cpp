#include "DxLib.h"
#include "Title.h"

Title::Title()
{
	TitleImg = 0;			// �^�C�g���摜
	AppleCursorImg = 0;		// �J�[�\���i�ԃ����S�j�摜
	menuNo = 0;			// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEND
	posY = 0;				// �J�[�\����Y���W
}

Title::~Title()
{

}

/****************************************
* �^�C�g����ʕ`��
*****************************************/
void Title::DrawTitle(XINPUT_STATE input, int& button_flg, int& gameMode)
{
	LoadTitleImages();		// �^�C�g���摜�Ǎ�

	// ���j���[�J�[�\���ړ�����
	if (input.ThumbLY < 128 && button_flg == FALSE) {
		button_flg = TRUE;
		if (++menuNo > 3) menuNo = 0;
	}
	if (input.ThumbLY > 128 && button_flg == FALSE) {
		button_flg = TRUE;
		if (--menuNo < 0) menuNo = 3;
	}
	if (input.ThumbLY == 128 && input.Buttons[XINPUT_BUTTON_A] == 0) {
		button_flg = FALSE;
	}

	// A�{�^���Ń��j���[�I��
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && button_flg == FALSE) {
		button_flg = TRUE;

		switch (menuNo) {
		case 0:
			gameMode = 1;			// INIT
			//GameMode = 6;			// RESULT
			break;
		case 1:
			gameMode = 3;			// RANKING
			break;
		case 2:
			gameMode = 4;			// HELP
			break;
		case 3:
			gameMode = 7;			// END
			break;
		}
	}

	// �^�C�g���摜�̕\��
	DrawGraph(0, 0, TitleImg, FALSE);

	// ���j���[�J�[�\���̕\��
	posY = menuNo * 100;

	// �J�[�\���i�ԃ����S�j���k���`��
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
}

/****************************************
* �^�C�g���摜�Ǎ�
*****************************************/
int Title::LoadTitleImages(void)
{
	// �^�C�g���摜�̓Ǎ�
	if ((TitleImg = LoadGraph("images/title.png")) == -1) return -1;
	// �J�[�\���i�ԃ����S�j�摜
	if ((AppleCursorImg = LoadGraph("images/redapple.png")) == -1) return -1;

	return 0;
}