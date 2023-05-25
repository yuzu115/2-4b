#include"DxLib.h"
#include"Keyboard.h"

#define ALPHA_MAX 26     // ���͏o���镶���̎�ނ̍��v
#define CURSOR_X  240    // �L�[�J�[�\���̏����ʒuX
#define CURSOR_Y  300    // �L�[�J�[�\���̏����ʒuY
#define KEY_WIDTH 60     //�m�[�}���L�[�̕�
#define KEY_HIGHT 60     //�m�[�}���L�[�̍���

int gBackImg; // �w�i�摜
int gKeyImg[4];  // �L�[�{�[�h�摜

//�ړ���   (�L�[�{�[�h�Z�Ԗ�)
int movekeyX = 0;
int movekeyY = 0;
CURSOR_TYPE CURSOR_NOW = CURSOR_TYPE::NORMAL;  //���݂̃J�[�\��
bool pushFlag = false;                         //A���@������Ă���/������ĂȂ� �t���O    TRUE:������Ă���@FALSE:������Ă��Ȃ�

int frame = 0;                   //�t���[�����J�E���g

char InputName[11];              //���͂�������������z�� 0�`9�ɕ���(10�������)�@10�Ԗڂɂ�\0
int input_Pos;                   //���͒��̔z��́Z�Ԗ�

// �L�[�{�[�h�Ɠ������т̔z��
const char AllStr[5][ALPHA_MAX / 2 + 1] =
{
	"ABCDEFGHIJKLM",
	"NOPQRSTUVWXYZ",
	"abcdefghijklm",
	"nopqrstuvwxyz",
	"0123456789"
};


int LoadInpNameImg(void)
{
	// �L�[�{�[�h�摜�̓Ǎ�
	if ((gKeyImg[0] = LoadGraph("images/�L�[�{�[�h.png")) == -1) return -1;
	// �w�i�摜�̓Ǎ�
	if ((gBackImg = LoadGraph("images/�w�i�Q.png")) == -1) return -1;

	return 0;
}

// �L�[�{�[�h������
void KeyBoardInit()
{
	//�J�[�\���̏����ʒu��"A"
	movekeyX = 0;             //������0�Ԗ�
	movekeyY = 0;             //������1�Ԗ�

	//�J�[�\���̏����ʒu�́uA�v�Ȃ̂Ńm�[�}��
	CURSOR_NOW = CURSOR_TYPE::NORMAL;

	//���͕�����@������
	for (int i = 0; i < 10; i++)
	{
		InputName[i] = 0;
	}
	InputName[10] = '\0';     //�z��̈�ԍŌ��"\0"(�I�[�̖ڈ�)�����Ă���

	input_Pos = -1;

	pushFlag = FALSE;         //�ŏ���A�{�^���͉�����Ă��Ȃ�
}
//�`��
void KeyBoard_Draw()
{
	// �w�i�摜�̕\��
	DrawExtendGraph(0, 0, 1280, 720, gBackImg, TRUE);
	// �L�[�{�[�h�摜�̕\��
	DrawExtendGraph(200, 250, 1090, 650, gKeyImg[0], TRUE);

	// �J�[�\��X
	int CurX = (CURSOR_X + KEY_WIDTH * movekeyX) + (2 * movekeyX);
	// �J�[�\��Y
	int CurY = CURSOR_Y + KEY_HIGHT * movekeyY;

	// �m�[�}��(A�`Z,a�`z,0�`9)�E�u�~�v�E�u�n�j�v�ɂ���ĉ摜�ω��@ switch���ő���
	switch (CURSOR_NOW)
	{
	case CURSOR_TYPE::NORMAL:    //�m�[�}���J�[�\��
		DrawCircle(CurX, CurY, 10, 0x2e8b57, TRUE);
		break;

	case CURSOR_TYPE::CANCEL:    //�u�~�v�J�[�\��
		DrawCircle(870, 540, 10, 0x2e8b57, TRUE);
		break;

	case CURSOR_TYPE::DONE:      //�uOK�v�J�[�\��
		// OK�L�[�I���J�[�\���摜�̕\��
		DrawCircle(580, 595, 10, 0x2e8b57, TRUE);
		break;

	default:
		break;
	}

	//���͒��̕�����\��
	DrawInputInfo();
}

//�X�V
void KeyBoard_Update(XINPUT_STATE input, int& Button_flg)
{
	//�t���[�����J�E���g
	frame++;

	if (input.ThumbLY > -2000 && input.ThumbLY < 2000 && input.Buttons[XINPUT_BUTTON_B] == 0)
	{
		Button_flg = FALSE;
	}
	if (input.ThumbLX > -2000 && input.ThumbLX < 2000 && input.Buttons[XINPUT_BUTTON_B] == 0)
	{
		Button_flg = FALSE;
	}

	//�� �E 
	if (input.ThumbLX > 2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		if (CursorControl() == true && CURSOR_NOW != CURSOR_TYPE::DONE)
		{
			movekeyX++;     //�^�C�~���O���� + �ړ�
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);
			*/
		}
		if (movekeyX > 12) movekeyX = 0;   //�E�[�ȏ�ō��[��

		CURSOR_NOW = CURSOR_TYPE::NORMAL;  //���݂̃L�[�̓m�[�}��
	}

	//�� ��
	if (input.ThumbLX < -2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		if (CursorControl() == true)
		{
			movekeyX--;     //�^�C�~���O���� + �ړ�
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);*/
		}
		if (movekeyX < 0) movekeyX = 12;     //���[�ȏ�ŉE�[��

		CURSOR_NOW = CURSOR_TYPE::NORMAL;    //���݂̃L�[�̓m�[�}��
	}

	//�� ��
	if (input.ThumbLY > 2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;

		if (CursorControl() == true)
		{
			
			movekeyY--;     //�^�C�~���O���� + �ړ�
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);*/
		}
		if (movekeyY <= 0) movekeyY = 0;     //��[�ŃX�g�b�v

		CURSOR_NOW = CURSOR_TYPE::NORMAL;         //���݂̃L�[�̓m�[�}��
	}

	//�� ��
	if (input.ThumbLY < -2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		if (CursorControl() == true)
		{
			
			movekeyY++;     //�^�C�~���O���� + �ړ�
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);*/
		}

		CURSOR_NOW = CURSOR_TYPE::NORMAL;         //���݂̃L�[�̓m�[�}��
	}

	//�u�~�v�{�^��   �ua�`z�v�i��艺 ���� �u9�v�L�[���E��
	if (movekeyY == 4 && movekeyX >= 10)
	{
		movekeyX = 10;                       //�{�^���̈ʒu

		CURSOR_NOW = CURSOR_TYPE::CANCEL;         //���݂̃L�[�̓L�����Z���u�~�v
	}

	//�uOK�v�{�^��   �L�[�{�[�h�ŉ��i��艺
	if (movekeyY >= 5)
	{
		movekeyX = 0;                        //�{�^���̈ʒu
		movekeyY = 5;

		CURSOR_NOW = CURSOR_TYPE::DONE;           //���݂̃L�[��DONE�uOK�v
	}

	DrawFormatString(0, 0, 0x000000, "Bflg:%d", input.Buttons[XINPUT_BUTTON_B]);
	DrawFormatString(0, 50, 0x000000, "Key:%d", CURSOR_NOW);

}

//�J�[�\���̈ړ��E�{�^���̒������𒲐�
bool CursorControl()
{
	int timing = 8;
	if (frame % timing == 0) return true;

	return false;
}

//B�{�^���������ꂽ���̏���
int KeyBoard_PushB(XINPUT_STATE input, char* name, int& Button_flg)
{
	//�@A�{�^���������Ă����
	if (input.Buttons[XINPUT_BUTTON_B] == 1 )
	{
		
		//�������ł̘A�����͂̃^�C�~���O�𒲐��iPC�̂悤�ȁj
		if (CursorControl() == true)
		{
			// "A�`Z","a�`z","1�`9"�̏�ŉ����ꂽ
			//PlaySoundMem(ClickKeyboard, DX_PLAYTYPE_BACK);
			// "A�`Z","a�`z","1�`9"�̏�ŉ����ꂽ
			if (CURSOR_NOW == CURSOR_TYPE::NORMAL)
			{
				pushFlag = true;        //������Ă����

				++input_Pos;            //���͈ʒu����E��

				//�����10����   �i�z���0�`9�j
				if (input_Pos > 9) input_Pos = 9;

				//�����z��ɓ���
				InputName[input_Pos] = AllStr[movekeyY][movekeyX];

			}
			else if (CURSOR_NOW == CURSOR_TYPE::CANCEL)                  //�u�~�v�L�[�̏�ŉ����ꂽ�@�ꕶ���폜
			{
				pushFlag = true;        //������Ă����

				if (input_Pos >= 0)
				{
					//�ꕶ���ł����͂���Ă���Έꕶ������
					if (InputName[input_Pos] != 0) InputName[input_Pos] = 0; //0 �͉������͂���Ă��Ȃ����

					input_Pos--;            //���͈ʒu�������

					//���͈ʒu�͍Œ�-1�܂�
					if (input_Pos < -1) input_Pos = -1;
				}

			}
			else if (CURSOR_NOW == CURSOR_TYPE::DONE)                  //�uOK�v�L�[�̏�ŉ����ꂽ�@�m��
			{
				if (input_Pos >= 0)
				{
					//�ꕶ�������͂���Ă��Ȃ��ꍇ�͊m��ł��Ȃ�
					if (InputName[input_Pos] != 0)
					{
						//�ꕶ���ł����̓A��

						InputName[input_Pos + 1] = '\0';       //�Ō�̕����̈�E��'\0'

						//�����L���O�ɓ��͓��e���Z�b�g
						strcpy_s(name, 11, InputName);

						/*DeleteFontToHandle(key_font);
						StopSoundMem(KeyboardBGM);*/
						return 1;   //�I��
					}
					else
					{
						//�_������I�@�@�Ȍ��ʉ�
					}
				}
			}
		}
	}
	else
	{
		pushFlag = false;          //������Ă��Ȃ���
	}

	if (input.Buttons[XINPUT_BUTTON_B] == 0)
	{
		Button_flg = FALSE;
	}

	return 0;
}


//���͏��\��
void DrawInputInfo()
{
	// �������͂���ĂȂ�
	if (InputName[0] == 0)
	{

		SetFontSize(23);
		DrawString(512, 148, "���O����͂��Ă�������", 0x616161);
	}

	// ���͂��ꂽ������\��
	for (int i = 0; InputName[i] != '\0'; i++)
	{
		SetFontSize(40);
		DrawFormatString(523 + 20 * i, 142, 0x616161, " %c", InputName[i]);
	}
}
