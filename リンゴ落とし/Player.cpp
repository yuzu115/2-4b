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
const int PLAYER_SPEED  = 5;    // �ړ����x

/******************************************
 * �\���̂̐錾
 ******************************************/
 // �v���C���[�̍\����
struct PLAYER
{
	int flg;       // �g�p�t���O
	float x, y;      // ���W
	int w, h;      // ���A����
	int speed;     // �ړ����x

};

// �v���C���[�̕ϐ��錾
struct PLAYER gPlayer;

/******************************************
 * �ϐ��̐錾
 ******************************************/
// �����S�̍��W
float ax, ay, ar;

/******************************************
 * �v���C���[������
 ******************************************/
// �v���C���[�̏����ݒ�
void PlayerInit(void)
{
	gPlayer.flg = TRUE;         
	gPlayer.x = PLAYER_POS_X;   
	gPlayer.y = PLAYER_POS_Y;   
	gPlayer.w = 76;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;

}

/*************************************
 * �v���C���[�̈ړ�
 *************************************/
void PlayerControl(int oldkey,int gamemode)
{

	// �v���C���[�̍��E�ړ�
	if (oldkey & PAD_INPUT_LEFT || oldkey & PAD_INPUT_RIGHT)
	{

		// ���ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed + 2;
		}
		// �����F���X�e�B�b�N�����ɌX����
		else if (oldkey & PAD_INPUT_LEFT)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x -= gPlayer.speed;
		}


		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x += gPlayer.speed + 2;
		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x += gPlayer.speed;
		}

	}
	// �v���C���[�̐Î~
	else
	{
	// �v���C���[���\��(��)
	DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);
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

	// �v���C���[�ƃ����S�̓����蔻�� 
	HitPlayer();

}

// �����S�̍��W��ϐ�sx,sy,sr�Ɋi�[
void GetApple(float ax0, float ay0, float ar0)
{
	// �����S�̍��W

	ax = ax0;
	ay = ay0;
	ar = ar0;

	//DrawCircle(sx, sy, sr, 0x000000, TRUE);

}

// ���+���̌v�Z
float Pythagorean(float px, float py, float ax, float ay)
{
	float dx, dy, r;

	dx = px - ax;
	dy = py - ay;

	r = (dx * dx) + (dy * dy);

	return (r);

}

// �����S�ƃv���C���[�̓����蔻��
void HitPlayer(void)
{
	// �����S�ƃv���C���[���������Ă��邩����
	int flg = 0;
	float mx0, mx1, my0, my1;

	mx0 = gPlayer.x;
	mx1 = gPlayer.x + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	// �v���C���[�̓����蔻��\��
	DrawBox(mx0, my0, mx1, my1, 0x000000, TRUE);
	// �����S�̓����蔻��\��
	DrawCircle(ax, ay, ar, 0x000000, TRUE);

	// 1:�~�̒��S�������`���猩�ď�E���E���̈ʒu�ɂ���ꍇ
	if ((mx0 < ax && ax < mx1) && (my0 - ar < ay && ay < my1 + ar))
	{
		flg = 1;
	}
	// 2:�~�̒��S�������`���猩�č��E���E�E�̈ʒu�ɂ���ꍇ
	if ((mx0 - ar < ax && ax < mx1 + ar) && (my0 < ay && ay < my1))
	{
		flg = 2;
	}
	// 3:�~�̒��S�������`���猩�Ď΂ߏ㉺�̈ʒu�ɂ���ꍇ
	if (Pythagorean(mx0, my0, ax, ay) < ar * ar || Pythagorean(mx1, my0, ax, ay) < ar *ar ||
		Pythagorean(mx0, my1, ax, ay) < ar * ar || Pythagorean(mx1, my1, ax, ay) < ar * ar)
	{
		flg = 3;
	}

    // ���1�`�R�̂ǂꂩ������Ă͂܂����瓖�����Ă���
	if (flg == 1 || flg == 2 || flg == 3)
	{
		// �������Ă����烊���S�̐F�𔒂�
		DrawCircle(ax, ay, ar, 0xffffff, TRUE);
	}
}

void PlayerFlashing() {

}