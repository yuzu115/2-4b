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
#include"InputControl.h"
#include"Keyboard.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;

//�����L���O�f�[�^�̕ϐ��錾
RankingData Ranking[RANK_MAX];

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	Player p;
	Apple app;

	app.AppleSet();
	p.LoadPlayerImg();

	//ScreenFlip�����s���Ă����������M����҂��Ȃ�
		//SetWaitVSyncFlag(FALSE);

	//���[�v�O��FPS�v����������
	Reset_fps();

	//// �v���C���[������
	//PlayerInit();

	// BACK�{�^���Ńv���O�����I��
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //��ʂ�������

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)

		InputControl::Update();

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			//case INIT:
			//	GameInit(GameMode);							// �Q�[��������
			//	break;
			case MAIN:
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				app.DrawApple();
				p.PlayerControl(g_OldKey, GameMode);

				//DrawApple();
				//PlayerControl(GameMode);						// �v���C���[����(joypad)
				//PlayerXControl(input, Button_flg);						// �v���C���[����(XInput)
				//PlayerXIControl(input);						// �v���C���[����(XInput)
				//PlayerFlashing(Count, on, off);					// �v���C���[�_��
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
		DrawFormatString(0, 16, 0x00000, "ThumbLX:%d ThumbLY:%d",input.ThumbLX, input.ThumbLY);


		//app.DrawApple();
	
		//���o�Ă�FPS�̕\��
		display_fps();

		//fps�̌v��
		Keisoku_fps();

		//�v���C���[����
		//p.PlayerControl(g_OldKey, GameMode);
		
		//PlayerFlashing(Count,on,off);

		if (GameMode == INPUTNAME)
		{
			DrawKeyboard();
		}

		//if (Count > 120)Count = 0;
		
		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�Œ菈��
		wait_fanc();

			//Count++;
			//off++;
			//on ++;
		
	}
	DxLib_End();

	return 0;
}

