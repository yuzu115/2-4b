#include"DxLib.h"
#include"infomation.h"
#include"Player.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	// FPS�̌v���ƕ\�����s�����[�J���ϐ��̐錾
	LONGLONG nowTime = GetNowHiPerformanceCount();
	LONGLONG oldTime = nowTime;
	LONGLONG fpsCheckTime;
	double deltaTime = 0;
	int fpsCounter = 0;
	int fps = 0;

	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X, SCREENSIZE_Y, 32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	// 
	GameMode = MAIN2;

	PlayerInit();

	// ���[�v�O��FPS�v����������
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;


	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{
		//�L�[���͎擾 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //��̃R���g���[���[�̓��͂��g���܂�
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //��ʂ�������

		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);

		if (GameMode == MAIN2)
		{
			PlayerControl(g_OldKey, GameMode);
			//HitBoxPlayer(PLAYER * p);
		}


		// FPS�̕\��
		SetFontSize(16);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA:%8.6fsec", fps, deltaTime);

		ScreenFlip();

	}

	DxLib_End();				           // �c�w���C�u�����g�p�̏I������

	return 0;				               // �\�t�g�̏I�� 
}

