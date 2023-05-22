#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"InputControl.h"


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
//int off, on=0;
//int gPlayerImg[];
int gWalkImg[6];
int gRanImg[6];
int Movex = 0;	//�������ʒu
int OPx = 0;	//���̈ʒu
int MoveRanx = 0;
int OPxRan = 0;
//int Sc[3]={10,35,50};

int Img;	//�����ɒB����܂ł̏����̊ԓ����摜��\����������p
int wImg;		//walkImg�̉摜�ǂ�\�����邩�̕\��

int RL = 0;	//�����E�����ʂ���ϐ�
int onceFlg = 1;//���ʂ�������Ă����x�������ׂ̃t���O
int a;

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


	OPx = gPlayer.x;
	OPxRan = gPlayer.x;

}

/*************************************
 * �v���C���[�̈ړ�
 *************************************/
void PlayerControl(int gamemode)
{
	LoadImg();

	// �v���C���[�̍��E�ړ�
	if (InputControl::GetKey(PAD_INPUT_LEFT) || InputControl::GetKey(PAD_INPUT_RIGHT))
	{
		// ���ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
		if (InputControl::GetKey(PAD_INPUT_LEFT) && InputControl::GetKey(PAD_INPUT_1))
		{
			RL = 0;
			PlayerRan(RL);

			gPlayer.x -= gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}

		// �����F���X�e�B�b�N�����ɌX����
		else if (InputControl::GetKey(PAD_INPUT_LEFT))
		{

			RL = 0;
			PlayerWalk(RL);
			gPlayer.x -= gPlayer.speed;
			Movex = gPlayer.x;
			
		}


		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
		if (InputControl::GetKey(PAD_INPUT_RIGHT) && InputControl::GetKey(PAD_INPUT_1))
		{
			RL = 3;
			PlayerRan(RL);

			gPlayer.x += gPlayer.speed + 2;
			MoveRanx = gPlayer.x;

		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (InputControl::GetKey(PAD_INPUT_RIGHT))
		{
			

			RL = 3;

			PlayerWalk(RL);
			gPlayer.x += gPlayer.speed;
			Movex = gPlayer.x;
			
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


	DrawFormatString(390, 30, 0x000000, "Movex=%d",Movex);
	DrawFormatString(390, 50, 0x000000, "OPx=%d",OPx);
	DrawFormatString(390, 70, 0x000000, "Movex-OPx=%d",abs(Movex-OPx));	
	DrawFormatString(390, 90, 0x000000, "onceFlg=%d",onceFlg);
	DrawFormatString(390, 110, 0x000000, "RL=%d",RL);

	DrawFormatString(390, 130, 0x000000, "MoveRanx=%d", MoveRanx);
	DrawFormatString(390, 150, 0x000000, "OPxRan=%d", OPxRan);
	DrawFormatString(390, 170, 0x000000, "MoveRanx-OPxRan=%d", abs(MoveRanx - OPxRan));
	//DrawFormatString(390, 190, 0x000000, "Move-12-OPRan=%d", abs(MoveRanx-12 - OPxRan));
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
	//DrawBox(mx0, my0, mx1, my1, 0x000000, TRUE);
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


//�摜��_�łł���悤�ɂ���
int PlayerFlashing(int& Count,int& on,int& off) {

	if (Count <= 120) {

		//120�b���܂ŁA20f���o�œ_��
		if (on == 20) {
			off = 0;

			DrawBox(0, 0, 40, 40, 0x000000, TRUE);
			// �v���C���[���\��(��)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);

			return off;

		}

		if (off == 20) {
			on = 0;
			DrawBox(0, 0, 40, 40, 0xff0000, FALSE);

			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x000000, TRUE);


			return on;
		}

	}
	
}

//Player�̕�������
void PlayerWalk(int wImg) {

	if (abs(Movex - OPx) > 50) {
		//OPx�������Ȃ��Ȃ�Ȃ��悤��
		OPx = Movex-10;
	}
	else {

	//��������
	switch (abs(Movex - OPx)) {
	case 10:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg], TRUE);
		Img = wImg;
		break;
	case 35:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg + 1], TRUE);
		Img = wImg + 1;
		break;
	case 50:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg + 2], TRUE);
		Img = wImg + 2;
		OPx = gPlayer.x;
		break;
	default:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[Img], TRUE);

	}

}

	
}

//Player�̑��铮��
void PlayerRan(int rImg)
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
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg], TRUE);
			Img = rImg;
			break;
		case 35:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 1], TRUE);
			Img = rImg + 1;
			break;
		case 56:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 2], TRUE);
			Img = rImg + 2;
			OPxRan = gPlayer.x;
			break;
		default:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[Img], TRUE);
		}

		//DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg+1], TRUE);
}

int LoadImg(void) {
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
	if (LoadDivGraph("images/PLwalk2.png", 6, 3, 2, 32, 32, gWalkImg) == -1)return -1;
	if (LoadDivGraph("images/PLRan.png", 6, 3, 2, 32, 32, gRanImg) == -1)return -1;
	return 0;
}

/*************************************
 * �v���C���[�̈ړ��iXInput�j
 *************************************/
void PlayerXControl(XINPUT_STATE input, int& Button_flg)
{
	LoadImg();

	// �v���C���[�̍��E�ړ��i���X�e�B�b�N�j
	if (input.ThumbLX < 128 || input.ThumbLX > 128)
	{
		// ���ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N�����ɌX����
		if (input.ThumbLX < 128 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			RL = 0;
			PlayerRan(RL);

			gPlayer.x -= gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}

		// �����F���X�e�B�b�N�����ɌX����
		else if (input.ThumbLX < 128)
		{
			RL = 0;
			PlayerWalk(RL);
			gPlayer.x -= gPlayer.speed;
			Movex = gPlayer.x;
		}

		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���E�ɌX����
		if (input.ThumbLX > 128 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			RL = 3;
			PlayerRan(RL);

			gPlayer.x += gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (input.ThumbLX > 128)
		{
			RL = 3;

			PlayerWalk(RL);
			gPlayer.x += gPlayer.speed;
			Movex = gPlayer.x;
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


	DrawFormatString(390, 30, 0x000000, "Movex=%d", Movex);
	DrawFormatString(390, 50, 0x000000, "OPx=%d", OPx);
	DrawFormatString(390, 70, 0x000000, "Movex-OPx=%d", abs(Movex - OPx));
	DrawFormatString(390, 90, 0x000000, "onceFlg=%d", onceFlg);
	DrawFormatString(390, 110, 0x000000, "RL=%d", RL);

	DrawFormatString(390, 130, 0x000000, "MoveRanx=%d", MoveRanx);
	DrawFormatString(390, 150, 0x000000, "OPxRan=%d", OPxRan);
	DrawFormatString(390, 170, 0x000000, "MoveRanx-OPxRan=%d", abs(MoveRanx - OPxRan));
	//DrawFormatString(390, 190, 0x000000, "Move-12-OPRan=%d", abs(MoveRanx-12 - OPxRan));
}

/*************************************
 * �v���C���[�̈ړ��iXInputStick�j
 *************************************/
void PlayerXIControl(XINPUT_STATE input)
{
	LoadImg();

	// �v���C���[�̍��E�ړ��i���X�e�B�b�N�j
	if (input.ThumbLX < 128 || input.ThumbLX > 128)
	{
		// ���ړ�
		// �_�b�V���F���X�e�B�b�N�����ɌX����
		if (input.ThumbLX < -150000)
		{
			RL = 0;
			PlayerRan(RL);

			gPlayer.x -= gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}

		// �����F���X�e�B�b�N�����ɌX����
		else if (input.ThumbLX < 128)
		{
			RL = 0;
			PlayerWalk(RL);
			gPlayer.x -= gPlayer.speed;
			Movex = gPlayer.x;
		}

		// �E�ړ�
		// �_�b�V���F���X�e�B�b�N���E�ɌX����
		if (input.ThumbLX > 15000)
		{
			RL = 3;
			PlayerRan(RL);

			gPlayer.x += gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}
		// �����F���X�e�B�b�N���E�ɌX����
		else if (input.ThumbLX > 128)
		{
			RL = 3;

			PlayerWalk(RL);
			gPlayer.x += gPlayer.speed;
			Movex = gPlayer.x;
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


	DrawFormatString(390, 30, 0x000000, "Movex=%d", Movex);
	DrawFormatString(390, 50, 0x000000, "OPx=%d", OPx);
	DrawFormatString(390, 70, 0x000000, "Movex-OPx=%d", abs(Movex - OPx));
	DrawFormatString(390, 90, 0x000000, "onceFlg=%d", onceFlg);
	DrawFormatString(390, 110, 0x000000, "RL=%d", RL);

	DrawFormatString(390, 130, 0x000000, "MoveRanx=%d", MoveRanx);
	DrawFormatString(390, 150, 0x000000, "OPxRan=%d", OPxRan);
	DrawFormatString(390, 170, 0x000000, "MoveRanx-OPxRan=%d", abs(MoveRanx - OPxRan));
	//DrawFormatString(390, 190, 0x000000, "Move-12-OPRan=%d", abs(MoveRanx-12 - OPxRan));
}
