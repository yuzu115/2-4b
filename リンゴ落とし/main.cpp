#include"DxLib.h"
#include"infomation.h"
#include "TITLE.h"
#include "RANKING.h"
#include "HELP.h"
#include "END.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;

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

	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h

		////���̓L�[�擾
		//g_OldKey = g_NowKey;
		//g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// �Q�[���p�b�h&�L�[�{�[�h
		//g_KeyFlg = g_NowKey & ~g_OldKey;
		
		switch (GameMode) {
			case TITLE:
				DrawTitle();		//�Q�[���^�C�g���`�揈��
				break;
			case RANKING:
				DrawRanking();		//�Q�[���^�C�g���`�揈��
				break;
			case HELP:
				DrawHelp();		//�w���v��ʕ`�揈��
				break;
			case END:
				DrawEnd();							//�G���h��ʕ`�揈��
				break;
		}

		ScreenFlip();	//����ʂ̓��e��\��ʂɔ��f

	}
	DxLib_End();	//DX���C�u�����g�p�̏I������

	return 0;	//�\�t�g�̏I��
}