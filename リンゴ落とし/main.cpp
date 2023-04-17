#include"DxLib.h"
#include"infomation.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{
		//���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// �Q�[���p�b�h�̃{�^��
		g_KeyFlg = g_NowKey & ~g_OldKey;
		
	//	GameMode = 0;			// �^�C�g����
		GameMode = 4;			// �w���v��

		switch (GameMode) {
			case TITLE:
				DrawTitle();		//�Q�[���^�C�g���`�揈��
				break;
			case HELP:
				DrawHelp();		//�w���v��ʕ`�揈��
				break;
		}

		ScreenFlip();	//����ʂ̓��e��\��ʂɔ��f

	}
	DxLib_End();	//DX���C�u�����g�p�̏I������

	return 0;	//�\�t�g�̏I��
}