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

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;

//�����L���O�f�[�^�̕ϐ��錾
RankingData Ranking[RANK_MAX];

int Time = 0;     //�҂�����
int StartTime;
int NowTime = 0;
int RefreshTime;
double Fps = 0.0;
int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;

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
	{
		RefreshTime = GetNowCount();

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)

		//���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// �Q�[���p�b�h&�L�[�{�[�h
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //��ʂ�������
		
		InputControl::Update();
		FpsTimeFanction();

		DrawFormatString(50, 60, 0x000000, "FPS %f", Fps); //fps��\��

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			case MAIN:
				PlayerInit();								// �v���C���[������
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				DrawApple();
				PlayerControl(GameMode);						// �v���C���[����
				//PlayerFlashing(Count, on, off);					// �v���C���[�_��
				break;
			case RANKING:
				DrawRanking(input,Ranking, Button_flg,GameMode);		//�����L���O�`�揈��
				break;
			case HELP:
				DrawHelp(input,Button_flg,GameMode);			//�w���v��ʕ`�揈��
				break;
			case END:
				DrawEnd(GameMode, Count);			//�G���h��ʕ`�揈��
				break;
			case RESULT:
				DrawResult(Ranking,GameMode);		//���U���g���
				break;
		}
		DrawFormatString(0, 16, 0x00000, "ThumbLX:%d ThumbLY:%d",
			input.ThumbLX, input.ThumbLY);
		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
		//DrawApple();
		
		//���o�Ă�FPS�̕\��
		display_fps();

		//fps�̌v��
		Keisoku_fps();
		
		// �v���C���[����
		//PlayerControl(GameMode);
		
		PlayerFlashing(Count,on,off);

		//PlayerImg();
		//PlayerControl(GameMode);

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


void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//���肵���l����fps���v�Z
		FpsTime_i = 0;//�J�E���g��������
				DrawFormatString(50, 60, 0x000000, "FPS %.1f", Fps); //fps��\��

	}
	else
		FpsTime_i++;//���݉����ڂ��J�E���g
	if (Fps != 0)
		DrawFormatString(50, 60, 0x000000, "FPS %.1f", Fps); //fps��\��
	return;
}