#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include"FPS.h"

int check;//120f�������
int on;//20f�������
int off;//20f�������

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

	if (check <= 120) {
		
		//120�b���܂ŁA20f���o�œ_��
		if (on == 20) {
			off = 0;

			DrawBox(0, 0, 40, 40, 0xffffff, TRUE);

		}

		if (off == 20) {
			on = 0;
			DrawBox(0, 0, 40, 40, 0x000000, FALSE);
		}

	}

	//if (check == 121)check = 0;

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�̌v��
		Keisoku_fps();

		//fps�Œ菈��
		wait_fanc();

		if (PAD_INPUT_1) {
			check++;
			on++;
			off++;
		}
		
	}
	DxLib_End();
	return 0;
}

