#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include"FPS.h"

int check;//120f�������
int on;//20f�������
int off;//20f�������

/*
*�l�p�`����̍��W
*x1��+40�ŉE��̍��W
* Y1��+40�ō����̍��W
//*/
//int x1 = 0;//�l�p�`�����x���W
//int Y1 = 0;//�l�p�`�����y���W
////���̂�y1���ƕϐ��錾���ł��Ȃ������̂�Y�P�Ő錾���Ă܂�
//
//int x2,y2 = 0;//�l�p�`������x,y���W


float x1, Y1 = 0;
float x2, y2 = 0;

float ip = 0;//����
float cp = 0;//�O��

//�����l�p�`�̖ʐ�
float m = 0;

float kx, ky = 0;

float a,b,c = 0;//�l�p�`����̍��W�v�Z�p //��
float a2, b2, c2 = 0;//�l�p�`�E���̍��W�v�Z�p //��

int a3, b3, c3 = 0;//�l�p�`�E��̍��W�v�Z�p //�I�����W
int a4, b4, c4 = 0;//�l�p�`�����̍��W�v�Z�p //��

int sx = 250;//�T�[�N���̂����W
int sy = 250;//�T�[�N���̂����W

int menseki = 0;

float h = 20.0f;//�~�̔��a

int gKeyFlg;//�L�[���͂���Ă邩
int gOldKey;
int gNowKey;

int key;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//���̓L�[�擾
	gOldKey = gNowKey;
	gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gKeyFlg = gNowKey & ~gOldKey;



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

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{

		//��ʂ̏�����
		ClearDrawScreen();
		
		//���o�Ă�FPS�̕\��
		display_fps();




		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			x1 -= 8;
			x2 -= 8;
		}

		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) 
		{

			x1 += 8;
			x2 += 8;
		}


		if (CheckHitKey(KEY_INPUT_UP)==1) {
			Y1-=8;
			y2-=8;
		}

		if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
			Y1+=8;
			y2+=8;

		}
		
	
		//�����l�p�`��DrawBox
		DrawBox(0 + x1, 0+Y1, 40+x2, 40+y2, 0xffff0f, TRUE);

		//�^�����̍��W������Ă�������̋�����{�ɂł��邩
		//box���ۂ��ł��邩�ǂ���
		//x��y�̍��W�ނ��ނ��͈͑��₹�邩�ǂ��������
		//�ʃA�v���[�`�ŉ~�ɔ����������Ă̂͂ǂ���
		//box�̐^�񒆂̍��W���甼�a�����
		//�^�񒆂���box�I���܂ł̂����Wx���W�Ƃ��Ă����ɐG������A������݂�����
		//�����������t�ɂ���Ƃ�
		
		ip = (40 * (x1-sx)) + (40 * c);
		//cp = (40*)

		//

		a = x1+20-sx;
		b = Y1+20-sy;
		c = sqrt(a * a + b * b);


		DrawCircle(x1+20,Y1+20, 3, 0x008080, TRUE);

		a2 = 40+x2 - sx;
		b2 = 40+y2 - sy;
		c2 = sqrt(a2 * a2 + b2 * b2);

		//x1�̂S�O��A�C�����E��̍��W�̍Č����āA�������狁�߂Ă�
		a3 = 40+x1 - sx;
		b3 = Y1 - sy;
		c3 = sqrt(a3 * a3 + b3 * b3);

		a4 = x1 - sx;
		b4 = 40+Y1 - sy;
		c4 = sqrt(a4 * a4 + b4 * b4);

		DrawCircle(sx, sy, h, 0xffffff, TRUE);

		m = (x2)*(y2);

		//���a���Ac�̒l���������Ȃ�����F���ς��
		//���a�P�O�O�ɓ����ė�����F���ς��
		//�~�̒��S����,���a�͂P�O�O�@���A�^�񒆂̋�������A�ǂ��܂łȂ�
		if (c<=h) {
			/*if () {

				DrawFormatString(390, 480, 0xffffff, "hit!!�F c=%d", c);
			}*/

			DrawCircle(sx, sy, h, 0x008080, TRUE);
		}


		//if (c2 <= h) {
		//	DrawCircle(sx, sy, h, 0x006400, TRUE);
		//}

		//if (c3 <= h) {
		//	DrawCircle(sx, sy, h, 0xffa500, TRUE);
		//}

		//if (c4 <= h) {
		//	DrawCircle(sx, sy, h, 0xdc143c, TRUE);
		//}

		

		DrawFormatString(390, 500, 0xffffff, "�F c=%f",c);
		DrawFormatString(390, 520, 0xffffff, "�� c2=%f",c2);
		DrawFormatString(390, 540, 0xffffff, "�I�����W�F c3=%d",c3);
		DrawFormatString(390, 560, 0xffffff, "�ԐF c4=%d",c4);
		DrawFormatString(390, 580, 0xffffff, "x1��sx�̋���=%f",a);
		DrawFormatString(390, 600, 0xffffff, "y1��sy�̋���=%f",b);
	


	if (check <= 120) {
		
		//120�b���܂ŁA20f���o�œ_��
		if (on == 20) {
			off = 0;

			DrawBox(0, 0, 40, 40, 0xffffff, TRUE);

		}

		if (off == 20) {
			on = 0;
			DrawBox(0, 0, 40, 40, 0x000000, FALSE);
		}

	}

	if (check == 121)check = 0;

		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		//fps�̌v��
		Keisoku_fps();

		//fps�Œ菈��
		wait_fanc();

		if (PAD_INPUT_1) {
			check++;
			on++;
			off++;
		}
		
	}
	DxLib_End();
	return 0;
}

