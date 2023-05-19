#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"
#include"Pause.h"

/******************************************
* �萔�̐錾
******************************************/
const int APPLE_MAX = 10;	//�����S�̍ő吶����
const int APPLE_TYPE=4;		//�����S�̎��

/******************************************
* �\���̂̐錾
******************************************/
struct AppleDate {
	int flg;		//�t���O
	int type;		//���
	int img;		//�摜�\���p
	float x, y, r;	//���W�A���a
	float speed;		//�������x
	int score;		//�X�R�A���Z
	int color;		//�F(��)
};

//�����S�̕ϐ�
struct AppleDate gApple[APPLE_MAX];

//�e�����S�̃f�[�^
struct AppleDate gApple_Rd = {TRUE,0,0,0,-40,45,1,100,0xff0000};	//��
struct AppleDate gApple_Br = {TRUE,1,0,0,-40,45,2,200,0x00ff00}; //��
struct AppleDate gApple_Gl = {TRUE,2,0,0,-40,45,3.5f,500,0xffff00}; //��
struct AppleDate gApple_Po = {TRUE,3,0,0,-40,45,0.5f,-750,0xff00ff}; //��

//�X�e�[�^�X�i�[�ϐ�
struct AppleDate gAppleState[APPLE_TYPE];

//�����i�[�ϐ�
int gRandApple;


/**
* �����S�̃f�[�^�i�[
*/
int AppleSet(void)
{
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Br;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	return 0;
}
	
/**
* �����S�̕`��
*/
void DrawApple(int& Pause_flg){


	for (int i = 0; i < APPLE_MAX; i++){
		
		// �����S�̕\��
		if (gApple[i].flg == TRUE) {
			DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, gApple[i].img, TRUE);


			if (Pause_flg == 0) {
				gApple[i].y += gApple[i].speed;
			}
			else
			{
				gApple[i].y -= gApple[i].speed;
			}


			//gApple��y���W��1000�ȉ��ɂȂ����Ƃ�����
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}
			DrawFormatString(0, 0, 0x000000, "speed:%f", gApple[i].speed);
			DrawFormatString(0, 20, 0x000000, "y:%d", gApple[i].y);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);


		}

		// �����S�̍��W�������Ƃ��ēn��
		GetApple(gApple[i].x,gApple[i].y,gApple[i].r);
		// �v���C���[�Ƃ̓����蔻��
		HitPlayer();
	}

	//�����֐��̓ǂݍ���
	CreateApple();

}


/**
* �����S�̐���
**/
int CreateApple()
{
	//�X�e�[�^�X�̓ǂݍ���
	AppleSet();

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gAppleState[gApple[i].type];	//�X�e�[�^�X�̊i�[
			gApple[i].type = RandApple();				//
			gApple[i].img = gApple[i].color;
			gApple[i].x = GetRand(7) * 125 + 50;
			gApple[i].speed = gApple[i].speed;
			gApple[i].flg = TRUE;
			return TRUE;
		}
	}
	return FALSE;
}  

/**
* �����S�̏o����
*/
int RandApple()
{
	gRandApple = GetRand(100);	//0�`100�܂ł̗������擾

	for (int i = 0; i < APPLE_MAX;i++)
	{
		//0�`59�ȉ��̐��l�Ȃ�ԃ����S(�߂�l:0)
		if (gRandApple <= 59)
		{
			return 0;
		}
		//60�`84�ȉ��̐��l�Ȃ�����S(�߂�l:1)
		else if (gRandApple <=84 && gRandApple>=60)
		{
			return 1;
		}
		//85�`94�ȉ��̐��l�Ȃ�������S(�߂�l:2)
		else if (gRandApple <= 94 && gRandApple>=84)
		{
			return 2;
		}
		//95�`100�ȉ��̐��l�Ȃ�Ń����S(�߂�l:3)
		else if (gRandApple <= 100 && gRandApple>=94)
		{
			return 3;
		}
	}
}


