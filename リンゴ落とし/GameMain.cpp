#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"
#include "Pause.h"

//�ϐ��錾
//int Pause_flg = 0;//flg 0������ĂȂ��� flg 1������Ă鎞


void GameMain(int& GameMode,XINPUT_STATE input, int& Button_flg,int& Pause_flg) {
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

}