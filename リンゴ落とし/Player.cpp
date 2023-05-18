#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"

float Player::ax, ay, ar;

float Player::mx0, mx1, my0, my1;

Player pl;
Apple ap;
/******************************************
 * �萔�̐錾
 ******************************************/
//// ��ʃT�C�Y
//const int SCREEN_WIDTH  = 1280;   // ��
//const int SCREEN_HEIGHT = 720;    // ����
//
// // �v���C���[�̏����l�̒萔
//const int PLAYER_POS_X  = 600;  // X���W 
//const int PLAYER_POS_Y  = 527;  // Y���W 
//const int PLAYER_SPEED  = 5;    // �ړ����x

/******************************************
 * �\���̂̐錾
 ******************************************/
// // �v���C���[�̍\����
//struct PLAYER
//{
//	int flg;       // �g�p�t���O
//	float x, y;      // ���W
//	int w, h;      // ���A����
//	int speed;     // �ړ����x
//
//};
//
//// �v���C���[�̕ϐ��錾
//struct PLAYER gPlayer;

/******************************************
 * �ϐ��̐錾
 ******************************************/
//// �����S�̍��W
//float ax, ay, ar;
//
//int LFlg = 0;
//int RFlg = 0;
//
//int gPlayerImg[5]; // �w�i�摜

/******************************************
 * �v���C���[������
 ******************************************/
// �v���C���[�̏����ݒ�
void Player::PlayerInit(void)
{
	gPlayer.flg = TRUE;
	gPlayer.x = PLAYER_POS_X;
	gPlayer.y = PLAYER_POS_Y;
	gPlayer.w = 80;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;

}

int Player::LoadPlayerImg(void)
{
	// �v���C���[(�E�����ɑ���)�摜�̓Ǎ�
	if ((gPlayerImg[0] = LoadGraph("images/�v���C���[�P.png")) == -1) return -1;
	// �v���C���[(�������ɑ���)�摜�̓Ǎ�
	if ((gPlayerImg[1] = LoadGraph("images/RunL.png")) == -1) return -1;
	// �v���C���[(�E�����ɕ���)�摜�̓Ǎ�
	if ((gPlayerImg[2] = LoadGraph("images/�v���C���[�Q.png")) == -1) return -1;
	// �v���C���[(�������ɕ���)�摜�̓Ǎ�
	if ((gPlayerImg[3] = LoadGraph("images/WalkL.png")) == -1) return -1;
	// �v���C���[(�Î~)�摜�̓Ǎ�
	if ((gPlayerImg[4] = LoadGraph("images/�v���C���[�R.png")) == -1) return -1;

	return 0;
}

/*************************************
 * �v���C���[�̈ړ�
 *************************************/
void Player::PlayerControl(int oldkey,int gamemode)
{
	LoadPlayerImg();

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
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed;
		}

		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			gPlayer.x += gPlayer.speed + 2;
			
		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
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
	if (gPlayer.x < -20)
	{
		gPlayer.x = -20;
	}
}

//// �����S�̍��W��ϐ�sx,sy,sr�Ɋi�[
//void Player::GetApple(float ax0, float ay0, float ar0)
//{
//	// �����S�̍��W
//
//	ax = ax0;
//	ay = ay0;
//	ar = ar0;
//
//	//DrawCircle(sx, sy, sr, 0x000000, TRUE);
//
//}

//// ���+���̌v�Z
//float Player::Pythagorean(float px, float py, float ax, float ay)
//{
//	float dx, dy, r;
//
//	dx = px - ax;
//	dy = py - ay;
//
//	r = (dx * dx) + (dy * dy);
//
//	return (r);
//
//}

// �����S�ƃv���C���[�̓����蔻��
int Player::HitPlayer(APPLE_DATE* a)
{
	// �����S�ƃv���C���[���������Ă��邩����
	int flg = 0;

	mx0 = gPlayer.x;
	mx1 = mx0 + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	ax = a->x;
	ay = a->y;
	ar = a->r;



	// �v���C���[�̓����蔻��\��
	//DrawBox(mx0, my0, mx1, my1, 0x000000, TRUE);
	// �����S�̓����蔻��\��
	//DrawCircle(ax, ay, ar, 0x000000, TRUE);

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
	if (pl.Pythagorean(mx0, my0, ax, ay) < ar * ar || pl.Pythagorean(mx1, my0, ax, ay) < ar *ar ||
		pl.Pythagorean(mx0, my1, ax, ay) < ar * ar || pl.Pythagorean(mx1, my1, ax, ay) < ar * ar)
	{
		flg = 3;
	}

    // ���1�`�R�̂ǂꂩ������Ă͂܂����瓖�����Ă���
	if (flg == 1 || flg == 2 || flg == 3)
	{
		// �������Ă����烊���S�̐F�𔒂�
		DrawCircle(ax, ay, ar, 0xffffff, TRUE);
		return TRUE;
	}
}