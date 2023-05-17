#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include "TITLE.h"
#include "RANKING.h"
#include "HELP.h"
#include "END.h"
#include "Result.h"
#include"DrawApple.h"
#include"FPS.h"
#include"Player.h"
#include"DrawApple.h"
#include"FPS.h"
#include"Player.h"
#include"InputControl.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
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

	//// �v���C���[������
	//PlayerInit();

	//ClearDrawScreen();                 //��ʂ�������

	// BACK�{�^���Ńv���O�����I��
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)

		//���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// �Q�[���p�b�h&�L�[�{�[�h
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //��ʂ�������
		
		InputControl::Update();

		//g_OldKey = g_NowKey;
		//g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //��̃R���g���[���[�̓��͂��g���܂�
		//g_KeyFlg = g_NowKey & ~g_OldKey;
		
		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			case MAIN:
				PlayerInit();						// �v���C���[������
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				DrawApple();
				// �v���C���[����
				PlayerControl(g_OldKey, GameMode);
				break;
			case RANKING:
				DrawRanking(input,Ranking, Button_flg,GameMode);		//�����L���O�`�揈��
				break;
			case HELP:
				DrawHelp(input,Button_flg,GameMode);			//�w���v��ʕ`�揈��
				break;
			case END:
				DrawEnd(GameMode);			//�G���h��ʕ`�揈��
				break;
			case RESULT:
				DrawResult(Ranking,GameMode);		//���U���g���
				break;
		}
		//ClearDrawScreen();                 //��ʂ�������



		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
		//DrawApple();
		
		//���o�Ă�FPS�̕\��
		display_fps();

		//fps�̌v��
		Keisoku_fps();
		
		// �v���C���[����
		//PlayerControl(GameMode);

		//PlayerFlashing(Count,on,off);

		//PlayerImg();
		PlayerControl(g_OldKey, GameMode);

		if (Count == 121)Count = 0;
		
		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�Œ菈��
		wait_fanc();

			Count++;
			off++;
			on ++;
		
		
	}
	DxLib_End();

	return 0;
}
