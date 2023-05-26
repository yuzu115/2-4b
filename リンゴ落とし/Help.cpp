#include "DxLib.h"
#include "Help.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int HelpImg;				// �w���v�摜

/****************************************
* �w���v��ʕ`��
*****************************************/
void DrawHelp(XINPUT_STATE input, int& Button_flg, int& GameMode)
{

	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	// A�{�^���Ń^�C�g����
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 0;					// TITLE
	}
	// B�{�^���ŃQ�[���X�^�[�g
	if (input.Buttons[XINPUT_BUTTON_B] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 1;					// INIT
		//GameMode = 9;					// END
	}

	// �摜�̕\��
	DrawGraph(0, 0, HelpImg, FALSE);

}

/****************************************
* �w���v�摜�Ǎ�
*****************************************/
int LoadHelpImages(void)
{
	// �w���v�摜�̓Ǎ�
	if ((HelpImg = LoadGraph("images/help.png")) == -1) return -1;

	return 0;
}