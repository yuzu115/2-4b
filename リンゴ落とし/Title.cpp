#include "DxLib.h"
#include "Title.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int TitleImg;			// �^�C�g���摜
int AppleCursorImg;		// �J�[�\���i�ԃ����S�j�摜
int CursorMoveSE;	//�J�[�\�����������̉�
int DecisionSE;		//����̉�

int menuNo = 0;			// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEND
int posY;				// �J�[�\����Y���W

/****************************************
* �^�C�g����ʕ`��
*****************************************/
void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode)
{

	ChangeVolumeSoundMem(220, CursorMoveSE);
	ChangeVolumeSoundMem(180, DecisionSE);

	// ���X�e�B�b�N�Ń��j���[�J�[�\���ړ�����
	// �X�e�B�b�N���͂������Ƃ��A�l���߂�Ȃ�����-2000��2000��ݒ肵�Ă���
	if (input.ThumbLY < -2000 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (++menuNo > 3) {
			menuNo = 0;
			PlaySoundMem(CursorMoveSE, DX_PLAYTYPE_BACK);
		}
	}
	if (input.ThumbLY > 2000 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (--menuNo < 0) {
			menuNo = 3;
			PlaySoundMem(CursorMoveSE, DX_PLAYTYPE_BACK);
		}
	}
	else if(input.ThumbLY > -2000 && input.ThumbLY < 2000 && input.Buttons[XINPUT_BUTTON_A] == 0)
	{
		Button_flg = FALSE;
	}

	// A�{�^���Ń��j���[�I��
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
		Button_flg = TRUE;

		switch (menuNo) {
			case 0:
				GameMode = 2;			// MAIN
				//GameMode = 6;			// RESULT
				break;
			case 1:
				GameMode = 3;			// RANKING
				break;
			case 2:
				GameMode = 4;			// HELP
				break;
	 		case 3:
				GameMode = 9;			// END
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
* �^�C�g���摜�A���ʉ��Ǎ�
*****************************************/
int LoadTitle(void)
{
	// �^�C�g���摜�̓Ǎ�
	if ((TitleImg = LoadGraph("images/title.png")) == -1) return -1;
	// �J�[�\���i�ԃ����S�j�摜
	if ((AppleCursorImg = LoadGraph("images/Apple_Red.png")) == -1) return -1;

	//�J�[�\���ړ��̉��Ǎ�
	if ((CursorMoveSE = LoadSoundMem("AppleSound/AppleSE/�J�[�\���ړ�12.wav")) == -1)return-1;
	//���艹�̓Ǎ�
	if ((DecisionSE = LoadSoundMem("AppleSound/AppleSE/�J�[�\���ړ�10.wav")) == -1)return-1;

	return 0;
}

