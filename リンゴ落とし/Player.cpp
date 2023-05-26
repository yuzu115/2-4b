#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"


float ax=0, ay=0, ar=0;

float mx0=0, mx1=0, my0=0, my1=0;

Apple app;
Player p;

int on = 20;	//20f�J�E���g�p
int off = 20;	//20f�J�E���g�p
int FlashCount=0;//�v���C���[�摜�_�ŗp
int Poflg=0;

int InitFlg=0;	//�������t���O

int LFlg = 0;
int RFlg = 0;

int gStopImg=0;
int gWalkImg[5]={0,0,0,0,0};
int gRanImg[7] = { 0,0,0,0,0,0,0};
int Movex = 0;	//�������ʒu
int OPx = 0;	//���̈ʒu
int MoveRunx = 0;
int OPxRun = 0;

int ImgRun = 0;	//�����ɒB����܂ł̏����̊ԓ����摜��\����������p
int ImgWalk = 0;	//�����ɒB����܂ł̏����̊ԓ����摜��\����������p
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
	gPlayer.w = 120;
	gPlayer.h = 140;
	gPlayer.speed = PLAYER_SPEED;

}

Player::~Player()
{

}

void Player::PlayerInit(void) {
	gPlayer.flg = TRUE;
	gPlayer.x = PLAYER_POS_X;
	gPlayer.y = PLAYER_POS_Y;
	gPlayer.w = 120;
	gPlayer.h = 140;
	gPlayer.speed = PLAYER_SPEED;

	Poflg = 0;
}

int Player::LoadPlayerImg(void)
{
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
		if (app.PoHit() != 1) {
			//// �������Ă����烊���S�̐F�𔒂�
			//DrawString(0, 150, "HIt", 0xffffff);
			flg = 4;

			return TRUE;
		}
		
	}
	return FALSE;
}

/*************************************
 * �v���C���[�̈ړ�(XInput)
 *************************************/
void Player::PlayerXControl(XINPUT_STATE input, int& Pause_flg)
{
	if (InitFlg == 1) {
		InitFlg = 0;
		PlayerInit();
	}

	if (Pause_flg == 0)
	{
		// �v���C���[�̍��E�ړ�
		// �X�e�B�b�N���͂������Ƃ��A�l���߂�Ȃ�����-20000��20000��ݒ肵�Ă���
		if (input.ThumbLX < -20000 || input.ThumbLX > 20000)
		{
			// ���ړ�
			// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
			if (input.ThumbLX < -20000 && input.Buttons[XINPUT_BUTTON_A] == 1)
			{
				RL = 0;
				PlayerRan(RL);
				gPlayer.x -= gPlayer.speed + 2;
				MoveRunx = gPlayer.x;
			}
			// �����F���X�e�B�b�N�����ɌX����
			else if (input.ThumbLX < -20000)
			{

				RL = 0;
				PlayerWalk(RL);
				gPlayer.x -= gPlayer.speed;
				Movex = gPlayer.x;

			}

			// �E�ړ�
			// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
			if (input.ThumbLX > 20000 && input.Buttons[XINPUT_BUTTON_A] == 1)
			{
				RL = 3;
				PlayerRan(RL);
				gPlayer.x += gPlayer.speed + 2;
				MoveRunx = gPlayer.x;
			}
			// �����F���X�e�B�b�N���E�ɌX����
			else if (input.ThumbLX > 20000)
			{
				RL = 2;
				PlayerWalk(RL);
				gPlayer.x += gPlayer.speed;
				Movex = gPlayer.x;

			}


		}
		// �v���C���[�̐Î~
		else
		{
			if (Poflg == 0) {
				//�v���C���[�~�܂��Ă�摜�\��
				DrawExtendGraph(gPlayer.x - 10, gPlayer.y, gPlayer.x + gPlayer.w + 10, SCREEN_HEIGHT, gStopImg, TRUE);

			}
		}
	}
	else
	{
		//�v���C���[�~�܂��Ă�摜�\��
		DrawExtendGraph(gPlayer.x-10, gPlayer.y, gPlayer.x + gPlayer.w+10, SCREEN_HEIGHT, gStopImg, TRUE);
}

	// ��ʂ��͂ݏo���Ȃ��悤�ɂ���
	// �E
	if (gPlayer.x > 930)
	{
		ImgWalk=2;
		ImgRun = 3;
		Movex = gPlayer.x;
		OPxRun = MoveRunx;
		gPlayer.x = 930;
	}
	// ��
	if (gPlayer.x < 0)
	{

		ImgWalk = 0;
		ImgRun = 0;
		Movex = gPlayer.x;
		OPxRun = MoveRunx;
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

	if (Poflg == 0) {

		if (abs(Movex - OPx) >= 31) {
			//��u�摜���\������Ȃ��Ȃ鎞�Ԃ��ł���̂ŕ\��
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[ImgWalk], TRUE);
			//OPx�������Ȃ��Ȃ�Ȃ��悤��
			OPx = Movex;
		}
		else {
			//��������
			switch (abs(Movex - OPx)) {
			case 10:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w , SCREEN_HEIGHT, gWalkImg[wImg], TRUE);
				ImgWalk = wImg;
				break;
			case 30:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg + 1], TRUE);
				ImgWalk = wImg + 1;
				OPx = gPlayer.x;
				break;
			default:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[ImgWalk], TRUE);

			}

		}
	}


}

//Player�̑��铮��
void Player::PlayerRan(int rImg)
{
	if (Poflg == 0) {

		if (abs(MoveRunx - OPxRun) >= 36) {
			/*OPx�������Ȃ��Ȃ�Ȃ��悤��
			������������Z�Ő؂�ւ����Ƃ��Acase�Ŕ���ł��鐔���A
			MoveRanx-OPxRan���傫���ꍇ�A�摜�������Ȃ��Ȃ��Ă��܂��̂�
			if���Ń��Z�b�g���Ă���*/
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[ImgRun], TRUE);
			OPxRun = MoveRunx;
		}
		//���铮��
			switch (abs(MoveRunx - OPxRun)) {
			case 7:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg], TRUE);
				ImgRun = rImg;
				break;
			case 21:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 1], TRUE);
				ImgRun = rImg + 1;
				break;
			case 35:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 2], TRUE);
				ImgRun = rImg + 2;
				OPxRun = gPlayer.x;
				break;
			default:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[ImgRun], TRUE);
			
		}
	}
	else {
		OPxRun = MoveRunx;
	}

}


//�摜��_�łł���悤�ɂ���
int Player::PlayerFlashing(void) {
	Poflg = 1;
	
		if (FlashCount < 121) {

			//120�b���܂ŁA20f���o�œ_��
			if (on > 0) {
				on -= 1;
				off = 20;
			}
			else if (off > 0) {
				Poflg = 0;
				off -= 1;
			}
			if (off == 0) {
				on = 20;
				Poflg = 1;
			}

		}

		if (FlashCount > 121)
		{
			Poflg = 0;
			app.Poget(0);
			on = 0;
			off = 0;
			FlashCount = 0;
		}

		FlashCount += 1;
	return 0;
}


void Player::Init(int Iflg)
{
	InitFlg = Iflg;
}