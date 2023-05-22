#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"
#include "Pause.h"

//�ϐ��錾
int RC=60;
int gNumImg[10];
int aR,aG,aY;


void DrawUI(int& GameMode,int& FC) {
	
	DrawBox(950+114, 0, 1280, 720, 0xfff8dc, TRUE);

	if (FC == 28) {
		RC -= 1;
	}

	if (RC == 0) {
		//60�b�������烊�U���g��ʂֈړ�
		GameMode = 6;
	}

	//DrawGraph(posx, 30, gNumberImg[tempScore % 10], TRUE);

	DrawFormatString(1200, 120, 0xffffff, "RC:%d", RC);
	DrawFormatString(130, 140, 0x000000, "FC:%d", FC);

	//Time�\��
	SetFontSize(52);
	DrawString(1070, 0, "TIME", 0x000000);
	SetFontSize(32);
	DrawString(1070, 60, "�c��", 0x000000);
	//DrawBox(1090, 110, 1280, 240, 0xfff8dc, TRUE);
	DrawExtendGraph(1090, 90, 1190, 220, gNumImg[RC / 10], TRUE);
	DrawExtendGraph(1180, 90, 1280, 220, gNumImg[RC % 10], TRUE);

	//�X�R�A���\��
	SetFontSize(52);
	DrawString(1070, 240, "Score", 0x000000);
	DrawString(1110, 295, "000000", 0x000000);

	//�����S����������\��
	SetFontSize(42);
	DrawString(1070, 355, "�l��\n   ���", 0x000000);
	//�ԃ����S
	DrawExtendGraph(1070, 430, 1160, 520, aR, TRUE);
	DrawString(1150, 475, " �~00", 0x000000);
	//�^�񒆂ɕ\�����V�^�̕��ɕ\�����ǂ�����
	DrawExtendGraph(1070, 530, 1160, 620, aG, TRUE);
	DrawExtendGraph(1070, 630, 1160, 720, aY, TRUE);
}

void GameMain(int& GameMode,XINPUT_STATE input, int& Button_flg,int& Pause_flg){
	//PlayerInit();								// �v���C���[������
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawApple(Pause_flg);
	PlayerControl(GameMode,Pause_flg);					// �v���C���[����
	//PlayerFlashing(Count, on, off);					// �v���C���[�_��

		// START�{�^���Ń��j���[�I��
		/*if (input.Buttons[XINPUT_BUTTON_START] == 1 && Button_flg == TRUE&& Pause_flg == 0)
		{
			Button_flg = FALSE;
			Pause_flg = 1;

		}
		
		if (input.Buttons[XINPUT_BUTTON_START] == 1 && Pause_flg == 1&& Button_flg == TRUE) {
			Pause_flg = 0;
		}*/
		
	//�|�[�Y����
		if (input.Buttons[XINPUT_BUTTON_START] == 1&& Button_flg == TRUE) {
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

		if (input.Buttons[XINPUT_BUTTON_START] == 0&& Button_flg == FALSE) {
			Button_flg = TRUE;
		}


		DrawFormatString(0, 120, 0x000000, "Pause_flg:%d", Pause_flg);
		DrawFormatString(0, 140, 0x000000, "b_flg:%d", Button_flg);
		//DrawUI(int& FC);
}

int LoadNumImg() {

	if (LoadDivGraph("images/Numbers.png", 10, 10, 1, 104, 152, gNumImg) == -1)return -1;
	aR = LoadGraph("images/RedApple.png");
	aG = LoadGraph("images/GreenApple.png");
	aY = LoadGraph("images/GoldApple.png");
}