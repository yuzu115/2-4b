#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"
#include "Pause.h"
#include "GameMain.h"

//�ϐ��錾
int RoopC = 60;
int FC = 0;
int gNumImg[10];
int aR, aG, aY;
int rc;			// �ԃ����S�̊l����
int bc;			// �����S�̊l����
int gc;			// �������S�̊l����
int Mainbgmflg=1;
int MainBGM;
int MainImg;

Player p;
Apple app;

void GetAppCount(Apple::AppScore* as)
{
	rc = as->r;
	bc = as->b;
	gc = as->g;
}

void DrawUI(int& GameMode, int& FC, int& Pause_flg) {


	// �w�i�摜�̕\��
	DrawGraph(0, 0, MainImg, FALSE);

	DrawBox(950 + 114, 0, 1280, 720, 0xfff8dc, TRUE);

	if (Pause_flg == 0) {

		if (FC == 28) {
			RoopC -= 1;
		}

		if (RoopC == 0) {
			//60�b�������烊�U���g��ʂֈړ�
			StopSoundMem(MainBGM);
			GameMode = 6;
		}

	}

	ChangeVolumeSoundMem(200, MainBGM);
	if (Pause_flg == 1) {
		StopSoundMem(MainBGM);

		Mainbgmflg = 1;
	}
	else {
		if (Mainbgmflg == 1) {

			PlaySoundMem(MainBGM, DX_PLAYTYPE_LOOP,FALSE);
		}
		Mainbgmflg = 0;
	}




	//Time�\��
	SetFontSize(52);
	DrawString(1070, 0, "TIME", 0x000000);
	SetFontSize(32);
	DrawString(1070, 60, "�c��", 0x000000);
	DrawExtendGraph(1090, 90, 1190, 220, gNumImg[RoopC / 10], TRUE);
	DrawExtendGraph(1180, 90, 1280, 220, gNumImg[RoopC % 10], TRUE);

	//�X�R�A���\��
	SetFontSize(52);
	DrawString(1070, 240, "Score", 0x000000);
	DrawFormatString(1110, 295, 0x000000, "%5d", app.GetScore());


	//�����S����������\��
	SetFontSize(42);
	DrawString(1070, 355, "�l��\n   ���", 0x000000);
	//�ԃ����S
	DrawExtendGraph(1070, 430, 1160, 520, aR, TRUE);
	DrawFormatString(1150, 475, 0x000000, "x%d", rc);

	//�΃����S
	DrawExtendGraph(1070, 530, 1160, 620, aG, TRUE);
	DrawFormatString(1150, 575, 0x000000, "x%d", bc);

	//�������S
	DrawExtendGraph(1070, 630, 1160, 720, aY, TRUE);
	DrawFormatString(1150, 675, 0x000000, "x%d", gc);
}

void GameMain(int& GameMode, XINPUT_STATE input, int& Button_flg, int& Pause_flg) {

	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawUI(GameMode, FC, Pause_flg);

	if (FC == 28) {

		FC = 0;
	}
	//PlayerInit();								// �v���C���[������
	app.DrawApple(Pause_flg);
	p.PlayerXControl(input, Button_flg, Pause_flg);					// �v���C���[����
	//PlayerFlashing(Count, on, off);					// �v���C���[�_��


	//�|�[�Y����
	if (input.Buttons[XINPUT_BUTTON_START] == 1 && Button_flg == TRUE) {
		Button_flg = FALSE;

		//Pause_flg=1 :�|�[�Y��
		//Pause_flg=0 :�|�[�Y������
		if (Pause_flg == 0) {
			Pause_flg = 1;
		}
		else {
			Pause_flg = 0;
		}
	}

	if (input.Buttons[XINPUT_BUTTON_START] == 0 && Button_flg == FALSE) {
		Button_flg = TRUE;
	}


	//DrawUI(int& FC);
	FC += 1;
}


int LoadNumImg() {

	// �w�i�摜�̓Ǎ�
	if ((MainImg = LoadGraph("images/back.png")) == -1) return -1;

	if (LoadDivGraph("images/Numbers.png", 10, 10, 1, 104, 152, gNumImg) == -1)return -1;
	aR = LoadGraph("images/Apple_Red.png");
	aG = LoadGraph("images/Apple_Blue.png");
	aY = LoadGraph("images/Apple_Gold.png");

	if ((MainBGM = LoadSoundMem("AppleSound/AppleBGM/���������C�ɃI���e�i�V.wav")) == -1)return -1;
}