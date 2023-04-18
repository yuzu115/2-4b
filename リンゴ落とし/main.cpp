#include"DxLib.h"
#include"infomation.h"
#include"DrawApple.h"
#include"Pause.h"
#include"Time.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	GameMode = PAUSE;

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{
		//�L�[���͎擾 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //��̃R���g���[���[�̓��͂��g���܂�
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //��ʂ�������

		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);

		//DrawApple();

		if (g_OldKey & PAD_INPUT_8)
		{
			switch (GameMode)
			{
			case PAUSE:
				pause(g_OldKey,GameMode);
				break;
			case MAIN:
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);

				DrawApple();

			}
		}

		ScreenFlip();

	}

	DxLib_End();				           // �c�w���C�u�����g�p�̏I������

	return 0;				               // �\�t�g�̏I�� 
}
