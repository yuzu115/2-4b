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
#include "GameMain.h"

/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;
int Pause_flg=0;
int UsuallyBGM;
int BGMflg=1;
int on2f = 20;
int off2f = 20;
int FlCount = 0;

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

	//�摜�A���ʉ��Ǎ�
	LoadImSE();


	Player p;
	Apple app;

	//ScreenFlip�����s���Ă����������M����҂��Ȃ�
		//SetWaitVSyncFlag(FALSE);

	//���[�v�O��FPS�v����������
	Reset_fps();

	// BACK�{�^���Ńv���O�����I��
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //��ʂ�������

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)


		if (GameMode == 2) {
			if (BGMflg == 0) {
				StopSoundMem(UsuallyBGM);
			}
			BGMflg = 1;
		}
		else {
			if (BGMflg == 1) {
				PlaySoundMem(UsuallyBGM, DX_PLAYTYPE_LOOP);
			}
			BGMflg = 0;
		}

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			case MAIN:
				GameMain(GameMode,input,Button_flg,Pause_flg);
				if (app.PoHit() == 1)p.PlayerFlashing();
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


		//DrawFormatString(0, 16, 0xff0000, "ThumbLX:%d ThumbLY:%d",input.ThumbLX, input.ThumbLY);
		//DrawFormatString(100, 100, 0x00ffff, "GameMode = %d",GameMode);
		

		//���o�Ă�FPS�̕\��
		display_fps();

		//fps�̌v��
		Keisoku_fps();



		if (GameMode == INPUTNAME)
		{
			DrawKeyboard();
		}

		
		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�Œ菈��
		wait_fanc();		

	


	}
	DxLib_End();

	return 0;
}


int LoadImSE(void) {
	Player p;
	Apple app;
	if ((UsuallyBGM = LoadSoundMem("AppleSound/AppleBGM/�X�[�p�[�ł�������.wav")) == -1)return -1;
	LoadTitle();
	app.AppleSet();
	p.LoadPlayerImg();
	LoadNumImg();
	LoadResultImages();					// ���U���g�摜�Ǎ�
	LoadHelpImages();					// �w���v�摜�Ǎ�
	LoadEndImages();				// �G���h�摜�Ǎ�
	KeyboardLoadImg();				// �摜�ǂݍ��݊֐����Ăяo��
	LoadRankingImages();		// �����L���O�摜�Ǎ�
}
