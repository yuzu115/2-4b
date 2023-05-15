#include "DxLib.h"
#include "infomation.h"
#include "TITLE.h"
//#include "RANKING.h"
//#include "HELP.h"
//#include "END.h"
//#include "Result.h"
#include "InputControl.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
//int Button_flg = FALSE;
int GameMode = 0;

//�����L���O�f�[�^�̕ϐ��錾
//RankingData Ranking[RANK_MAX];

/****************************************************
*�v���O�����̊J�n
******************************************************/
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	// BACK�{�^���Ńv���O�����I��
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		//GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)

		InputControl::Update();				// ���̓L�[�̎擾

		switch (GameMode) {
			case TITLE:
				DrawTitle(GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			//case RANKING:
			//	DrawRanking(input,Ranking, Button_flg,GameMode);		//�����L���O�`�揈��
			//	break;
			//case HELP:
			//	DrawHelp(input,Button_flg,GameMode);			//�w���v��ʕ`�揈��
			//	break;
			//case END:
			//	DrawEnd(GameMode);			//�G���h��ʕ`�揈��
			//	break;
			//case RESULT:
			//	DrawResult(Ranking,GameMode);		//���U���g���
			//	break;
		}

		ScreenFlip();	//����ʂ̓��e��\��ʂɔ��f

	}
	DxLib_End();	//DX���C�u�����g�p�̏I������

	return 0;	//�\�t�g�̏I��
}