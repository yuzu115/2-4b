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
#include "GameMain.h"
#include "Pause.h"
#include"Keyboard.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int Pause_flg = FALSE;
int GameMode = 0;

//�����L���O�f�[�^�̕ϐ��錾
RankingData Ranking[RANK_MAX];

int LoadImages();

//Count�ϐ��錾
int RoopCount = 0;
int Count = 0;
int on = 0;
int off = 0;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("�����S���Ƃ�");
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	//ScreenFlip�����s���Ă����������M����҂��Ȃ�
	//SetWaitVSyncFlag(0);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	Player p;
	Apple app;

	app.AppleSet();
	p.LoadPlayerImg();

	//ScreenFlip�����s���Ă����������M����҂��Ȃ�
		//SetWaitVSyncFlag(FALSE);
	//�摜�Ǎ�
	/*�e�֐��œǂݍ��ނƎ��Ԃ��|������FPS���啝�ɒx���ׁA
	�Q�[�����[�v���n�܂�O�ɂ��炩���߉摜�A�T�E���h�Ȃǂ�ǂݍ��ފ֐������
	��ɓǂݍ���ł���*/
	if (LoadImages() == -1)return -1;

	//���[�v�O��FPS�v����������
	Reset_fps();


	// BACK�{�^���Ńv���O�����I��
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //��ʂ�������

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)

		//���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// �Q�[���p�b�h&�L�[�{�[�h
		g_KeyFlg = g_NowKey & ~g_OldKey;

		InputControl::Update();

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//�Q�[���^�C�g���`�揈��

				break;
			//case INIT:
			//	GameInit(GameMode);							// �Q�[��������
			//	break;
			case MAIN:

				GameMain(GameMode, input, Button_flg, Pause_flg);
				DrawUI(GameMode, RoopCount, Pause_flg);
				//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
			
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
		DrawFormatString(0, 16, 0xff0000, "ThumbLX:%d ThumbLY:%d",input.ThumbLX, input.ThumbLY);
		DrawFormatString(100, 100, 0x00ffff, "GameMode = %d",GameMode);

		if (input.Buttons[XINPUT_BUTTON_B] == 1)
		{
			GameMode = 6;
		}
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

		if (Count == 121)Count = 0;
		if (RoopCount == 28)RoopCount = 0;
		

		//fps�̌v��
		Keisoku_fps();
		//���o�Ă�FPS�̕\��
		display_fps();

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�Œ菈��
		wait_fanc();

		RoopCount++;

			Count++;
			off++;
			on ++;
		
		
	}
	DxLib_End();

	return 0;
}


int LoadImages() {
	if(LoadTitleImages()==-1) return -1;
	if (LoadImg() == -1)return -1;
	if (LoadNumImg() == -1)return -1;
	//LoadImg();
	return 0;
}