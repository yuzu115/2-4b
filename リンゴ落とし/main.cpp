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
*/
int x1 = 0;
int Y1 = 0;
//���̂�y1���ƕϐ��錾���ł��Ȃ������̂�Y�P�Ő錾���Ă܂�

int x2,y2 = 0;//�l�p�`�����̍��W

int a,b,c = 0;//�l�p�`����̍��W�v�Z�p
int a2, b2, c2 = 0;//�l�p�`�E���̍��W�v�Z�p

int a3, b3, c3 = 0;//�l�p�`�E��̍��W�v�Z�p
int a4, b4, c4 = 0;//�l�p�`����̍��W�v�Z�p

int sx = 250;//�T�[�N���̂����W
int sy = 250;//�T�[�N���̂����W

int menseki = 0;

float h = 100.0f;//�~�̔��a

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
		
	

		DrawBox(0 + x1, 0+Y1, 40+x2, 40+y2, 0xffff0f, TRUE);


		a = x1 - sx;
		b = Y1 - sy;
		c = sqrt(a * a + b * b);


		a2 = 40+x2 - sx;
		b2 = 40+y2 - sy;
		c2 = sqrt(a2 *a2 + b2 * b2);

		//x1�̂S�O��A�C�����E��̍��W�̍Č����āA�������狁�߂Ă�
		a3 = 40+x1 - sx;
		b3 = Y1 - sy;
		c3 = sqrt(a3 * a3 + b3 * b3);

		a4 = x1 - sx;
		b4 = 40+Y1 - sy;
		c4 = sqrt(a4 * a4 + b4 * b4);

		DrawCircle(sx, sy, h, 0xffffff, TRUE);

		//���a���Ac�̒l���������Ȃ�����F���ς��
		//���a�P�O�O�ɓ����ė�����F���ς��
		if (c <= h) {

			DrawCircle(sx, sy, h, 0x008080, TRUE);
		}


		if (c2 <= h) {
			DrawCircle(sx, sy, h, 0x006400, TRUE);
		}

		if (c3 <= h) {
			DrawCircle(sx, sy, h, 0xffa500, TRUE);
		}

		if (c4 <= h) {
			DrawCircle(sx, sy, h, 0xdc143c, TRUE);
		}


		DrawFormatString(390, 500, 0xffffff, "�I�����W�F c3=%d",c3);
	


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

	//if (check == 121)check = 0;

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

