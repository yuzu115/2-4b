#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include"FPS.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���


	//ScreenFlip�����s���Ă����������M����҂��Ȃ�
		//SetWaitVSyncFlag(FALSE);

	//���[�v�O��FPS�v����������
	Reset_fps();

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{

		//��ʂ̏�����
		ClearDrawScreen();
		
		//���o�Ă�FPS�̕\��
		display_fps();

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�̌v��
		Keisoku_fps();

		ScreenFlip();

		//fps�Œ菈��
		wait_fanc();

	}
	DxLib_End();
	return 0;
}

