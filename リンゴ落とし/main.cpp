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

	Title title;
	Help help;
	End end;

	Player p;
	Apple app;

	// �摜�Ǎ�
	title.LoadTitleImages();			// �^�C�g���摜�Ǎ�
	LoadRankingImages();				// �����L���O�摜�Ǎ�
	help.LoadHelpImages();				// �w���v�摜�Ǎ�
	end.LoadEndImages();				// �G���h�摜�Ǎ�
	LoadResultImages();			// ���U���g�摜�Ǎ�

	app.AppleSet();
	p.LoadPlayerImg();

	//ScreenFlip�����s���Ă����������M����҂��Ȃ�
		//SetWaitVSyncFlag(FALSE);

	//���[�v�O��FPS�v����������
	Reset_fps();

	// BACK�{�^���Ńv���O�����I��
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //��ʂ�������

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// �Q�[���p�b�h(XInput)

		switch (GameMode) {
			case TITLE:
				title.DrawTitle(input,Button_flg,GameMode);		//�Q�[���^�C�g���`�揈��
				break;
			case MAIN:
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				app.DrawApple();
				p.PlayerXControl(input);
				break;
			case RANKING:
				DrawRanking(input,Ranking, Button_flg,GameMode);		//�����L���O�`�揈��
				break;
			case HELP:
				help.DrawHelp(input,Button_flg,GameMode);			//�w���v��ʕ`�揈��
				break;
			case END:
				end.DrawEnd(GameMode);			//�G���h��ʕ`�揈��
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

