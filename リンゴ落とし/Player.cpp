#include"DxLib.h"
#include <math.h>
#include"Player.h"


/******************************************
 * �萔�̐錾
 ******************************************/
// ��ʃT�C�Y
const int SCREEN_WIDTH  = 1280;   // ��
const int SCREEN_HEIGHT = 720;    // ����

 // �v���C���[�̏����l�̒萔
const int PLAYER_POS_X  = 600;  // X���W 
const int PLAYER_POS_Y  = 570;  // Y���W 
const int PLAYER_SPEED  = 2;    // �ړ����x

/******************************************
 * �\���̂̐錾
 ******************************************/
 // �v���C���[�̍\����
struct PLAYER
{
	int flg;       // �g�p�t���O
	int x, y;      // ���W
	int w, h;      // ���A����
	int speed;     // �ړ����x

};

// �v���C���[�̕ϐ��錾
struct PLAYER gPlayer;

/******************************************
 * �v���C���[������
 ******************************************/
// �v���C���[�̏����ݒ�
void PlayerInit(void)
{
	gPlayer.flg = TRUE;         
	gPlayer.x = PLAYER_POS_X;   
	gPlayer.y = PLAYER_POS_Y;   
	gPlayer.w = 50;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;
}

// �����蔻��m�F�p�������S�\��
int testX = 640;
int testY = 360;
int testR = 10;

/*************************************
 * �v���C���[�̈ړ�
 *************************************/
void PlayerControl(int oldkey,int gamemode)
{
	// �����S���\��(���F)
	DrawCircle(testX, testY, testR, 0xff0000, TRUE);

	// �v���C���[�̍��E�ړ�
	if (oldkey & PAD_INPUT_LEFT || oldkey & PAD_INPUT_RIGHT)
	{

		// ���ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0xff0000, TRUE);

			gPlayer.x -= gPlayer.speed + 1;
		}
		// �����F���X�e�B�b�N�����ɌX����
		else if (oldkey & PAD_INPUT_LEFT)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x -= gPlayer.speed;
		}
		

		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x += gPlayer.speed + 1;
		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x += gPlayer.speed;
		}
		
	}
	// �v���C���[�̐Î~
	else
	{
		// �v���C���[���\��(��)
		DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0xffffff, TRUE);
	}

	// ��ʂ��͂ݏo���Ȃ��悤�ɂ���
	// �E
	if (gPlayer.x > 950)
	{
		gPlayer.x = 950;
	}
	// ��
	if (gPlayer.x < 0)
	{
		gPlayer.x = 0;
	}

	// �����蔻��m�F�p�������S�\��
	if (oldkey & PAD_INPUT_DOWN)
	{
		// �����S���\��(���F)
		DrawCircle(testX, testY, testR, 0xff0000, TRUE);
		testY += 2;
	}
	// �����蔻��m�F�p�������S�\��
	if (oldkey & PAD_INPUT_UP)
	{
		// �����S���\��(���F)
		DrawCircle(testX, testY, testR, 0xff0000, TRUE);
		testY -= 2;
	}

	// ��ʂ��͂ݏo���Ȃ��悤�ɂ���
	// �E
	if (testY > 710)
	{
		testY = 710;
	}
	// ��
	if (testY < 10)
	{
		testY = 10;
	}


}

/*************************************
 * �v���C���[�̓����蔻��
 *************************************
void HitBoxPlayer(void)
{
	int x1, x2, y1, y2;

	x1 = gPlayer.x;
	x2 = gPlayer.x + gPlayer.w;
	y1 = gPlayer.y;
	y2 = gPlayer.y + gPlayer.h;

	//DrawBox(x1, y1, x2, y2, 0x00ff00, TRUE);

	int cx, cy, cr;

	cx = testX;
	cy = testY;
	cr = testR;

	DrawCircle(cx, cy, cr, 0xffff00, TRUE);

	int c2;

	c2 = (x1 - x )


	if ((cx > x1 - cr) && (cx < y1 + cr) && (cy > x2 - cr) && (cy < y2 + cr))
	{
		DrawCircle(testX, testY, testR, 0xff0000, TRUE);
		DrawBox(x1, y1, x2, y2, 0x00ff00, TRUE);
	}


}*/
