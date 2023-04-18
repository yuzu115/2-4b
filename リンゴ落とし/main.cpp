#include"DxLib.h"
#include"infomation.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"

/********************************************************************
*�@�ϐ��̐錾
********************************************************************/
int g_OldKey;                  //�O��̓��̓L�[
int g_NowKey;                  //����̓��̓L�[
int g_KeyFlg;                  //���̓L�[���

int GameMode = 0;

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
		
		switch (GameMode) {
			case TITLE:
				DrawTitle(g_KeyFlg,GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			case HELP:
				DrawHelp(g_KeyFlg,GameMode);		//�w���v��ʕ`�揈��
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