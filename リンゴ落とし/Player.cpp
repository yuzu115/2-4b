#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"


int gPlayerImg[5]; // �w�i�摜
float ax, ay, ar;

float mx0, mx1, my0, my1;

int LFlg = 0;
int RFlg = 0;

int gStopImg;
int gWalkImg[4];
int gRanImg[6];
int Movex = 0;	//�������ʒu
int OPx = 0;	//���̈ʒu
int MoveRanx = 0;
int OPxRan = 0;
//int Sc[3]={10,35,50};

int Img = 0;	//�����ɒB����܂ł̏����̊ԓ����摜��\����������p
int wImg = 0;		//walkImg�̉摜�ǂ�\�����邩�̕\��

int RL = 0;	//�����E�����ʂ���ϐ�

/******************************************
 * �v���C���[������
 ******************************************/

Player::Player()
{
	gPlayer.flg = TRUE;
	gPlayer.x = PLAYER_POS_X;
	gPlayer.y = PLAYER_POS_Y;
	gPlayer.w = 80;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;
}

Player::~Player()
{

}


int Player::LoadPlayerImg(void)
{
	//// �v���C���[(�E�����ɑ���)�摜�̓Ǎ�
	//if ((gPlayerImg[0] = LoadGraph("images/�v���C���[�P.png")) == -1) return -1;
	//// �v���C���[(�������ɑ���)�摜�̓Ǎ�
	//if ((gPlayerImg[1] = LoadGraph("images/RunL.png")) == -1) return -1;
	//// �v���C���[(�E�����ɕ���)�摜�̓Ǎ�
	//if ((gPlayerImg[2] = LoadGraph("images/�v���C���[�Q.png")) == -1) return -1;
	//// �v���C���[(�������ɕ���)�摜�̓Ǎ�
	//if ((gPlayerImg[3] = LoadGraph("images/WalkL.png")) == -1) return -1;
	//// �v���C���[(�Î~)�摜�̓Ǎ�
	//if ((gPlayerImg[4] = LoadGraph("images/�v���C���[�R.png")) == -1) return -1;

	//�摜�����ǂݍ���
	/*�ȉ�LoadDivGraph�̈����̓��e
	*�t�@�C����
	*�摜�̐�
	*�������̉摜�̐�
	*�c�����̉摜�̐�
	*�摜��̉��T�C�Y
	*�摜��̏c�T�C�Y
	*�摜���i�[����z��
	*/
	if (LoadDivGraph("images/BearWalk.png", 4, 2, 2, 32, 32, gWalkImg) == -1)return -1;
	if (LoadDivGraph("images/BearRan.png", 6, 3, 2, 32, 32, gRanImg) == -1)return -1;
	if ((gStopImg = LoadGraph("images/kuma.png")) == -1) return -1;


	return 0;
}

///*************************************
// * �v���C���[�̈ړ�
// *************************************/
//void Player::PlayerControl(int oldkey,int gamemode)
//{
//
//	// �v���C���[�̍��E�ړ�
//	if (oldkey & PAD_INPUT_LEFT || oldkey & PAD_INPUT_RIGHT)
//	{
//		// ���ړ�
//		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
//		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
//		{
//			// �v���C���[���\��(��)
//			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
//			gPlayer.x -= gPlayer.speed + 2;
//		}
//		// �����F���X�e�B�b�N�����ɌX����
//		else if (oldkey & PAD_INPUT_LEFT)
//		{
//			// �v���C���[���\��(���F)
//			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
//			gPlayer.x -= gPlayer.speed;
//		}
//
//		// �E�ړ�
//		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
//		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
//		{
//			// �v���C���[���\��(��)
//			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
//			gPlayer.x += gPlayer.speed + 2;
//			
//		}
//		// �����F���X�e�B�b�N���E�ɌX����
//		else if (oldkey & PAD_INPUT_RIGHT)
//		{
//			// �v���C���[���\��(���F)
//			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
//			gPlayer.x += gPlayer.speed;
//			
//		}
//
//
//	}
//	// �v���C���[�̐Î~
//	else
//	{
//	// �v���C���[���\��(��)
//		DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);
//	}
//
//	// ��ʂ��͂ݏo���Ȃ��悤�ɂ���
//	// �E
//	if (gPlayer.x > 950)
//	{
//		gPlayer.x = 950;
//	}
//	// ��
//	if (gPlayer.x < -20)
//	{
//		gPlayer.x = -20;
//	}
//
//	mx0 = gPlayer.x;
//	mx1 = mx0 + gPlayer.w;
//	my0 = gPlayer.y;
//	my1 = SCREEN_HEIGHT;
//
//	HitPlayer();
//}


// ���+���̌v�Z
float Player::Pythagorean(float px, float py, float ax, float ay)
{
	float dx, dy, r;

	dx = px - ax;
	dy = py - ay;

	r = (dx * dx) + (dy * dy);

	return (r);

}

void Player::GetApple(Apple::APPLE_DATA* a)
{
	ax = a->x;
	ay = a->y;
	ar = a->r;
}

// �����S�ƃv���C���[�̓����蔻��
int Player::HitPlayer(void)
{
	// �����S�ƃv���C���[���������Ă��邩����
	int flg = 0;

	//DrawBox(mx0, my0, mx1,my1, 0x000000, TRUE);
	//DrawCircle(ax, ay, ar, 0xffffff, TRUE);

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
		return TRUE;
	}

	return FALSE;
}

/*************************************
 * �v���C���[�̈ړ�(XInput)
 *************************************/
void Player::PlayerXControl(XINPUT_STATE input)
{

	// �v���C���[�̍��E�ړ�
	// �X�e�B�b�N���͂������Ƃ��A�l���߂�Ȃ�����-2000��2000��ݒ肵�Ă���
	if (input.ThumbLX < -2000 || input.ThumbLX > 2000)
	{
		// ���ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
		if (input.ThumbLX < -2000 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed + 2;
		}
		// �����F���X�e�B�b�N�����ɌX����
		else if (input.ThumbLX < -2000)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed;
		}

		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
		if (input.ThumbLX > 2000 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			gPlayer.x += gPlayer.speed + 2;

		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (input.ThumbLX > 2000)
		{
			// �v���C���[���\��(���F)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			gPlayer.x += gPlayer.speed;

			}


		}
		// �v���C���[�̐Î~
		else
		{
			//// �v���C���[���\��(��)
			//DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);
			//�v���C���[�~�܂��Ă�摜�\��
			DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gStopImg, TRUE);
		}
	}else {
		//�v���C���[�~�܂��Ă�摜�\��
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gStopImg, TRUE);

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

	mx0 = gPlayer.x;
	mx1 = mx0 + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	HitPlayer();
}


//Player�̕�������
void Player::PlayerWalk(int wImg) {

	if (abs(Movex - OPx) > 50) {
		//��u�摜���\������Ȃ��Ȃ鎞�Ԃ��ł���̂ŕ\��
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gWalkImg[Img], TRUE);
		//OPx�������Ȃ��Ȃ�Ȃ��悤��
		OPx = Movex - 10;
	}
	else {
		//��������
		switch (abs(Movex - OPx)) {
		case 20:
			DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gWalkImg[wImg], TRUE);
			Img = wImg;
			break;
		case 50:
			DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gWalkImg[wImg + 1], TRUE);
			Img = wImg + 1;
			OPx = gPlayer.x;
			break;
		default:
			DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gWalkImg[Img], TRUE);

		}

	}


}

//Player�̑��铮��
void Player::PlayerRan(int rImg)
{
	if (abs(MoveRanx - OPxRan) > 56) {
		/*OPx�������Ȃ��Ȃ�Ȃ��悤��
		������������Z�Ő؂�ւ����Ƃ��Acase�Ŕ���ł��鐔���A
		MoveRanx-OPxRan���傫���ꍇ�A�摜�������Ȃ��Ȃ��Ă��܂��̂�
		if���Ń��Z�b�g���Ă���*/
		OPxRan = MoveRanx;
	}
	//���铮��
	switch (abs(MoveRanx - OPxRan)) {
	case 21:
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gRanImg[rImg], TRUE);
		Img = rImg;
		break;
	case 35:
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gRanImg[rImg + 1], TRUE);
		Img = rImg + 1;
		break;
	case 56:
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gRanImg[rImg + 2], TRUE);
		Img = rImg + 2;
		OPxRan = gPlayer.x;
		break;
	default:
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gRanImg[Img], TRUE);
	}

	//DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg+1], TRUE);
}