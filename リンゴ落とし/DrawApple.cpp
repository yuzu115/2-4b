#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"

#define APPLE_MAX  10	//�����S�̍ő吶����
#define APPLE_TYPE  4		//�����S�̎��
#define APPLE_SIZE  400

struct APPLE_DATE {
	int flg;		//�t���O
	int type;		//���
	int img;		//�摜�\���p
	float x, y, r;		//���W�A���a
	float speed;		//�������x
	int score;		//�X�R�A���Z
	float size;		//�����蔻��̔{��
};
//�����S�̕ϐ�
struct APPLE_DATE gApple[APPLE_MAX];

//�e�����S�̃f�[�^
struct APPLE_DATE gApple_Rd = { TRUE,0,0,0,-40,45,1,100,1.1f };	//��
struct APPLE_DATE gApple_Bl = { TRUE,1,0,0,-40,45,2,200,1.1f }; //��
struct APPLE_DATE gApple_Gl = { TRUE,2,0,0,-40,45,3.5f,500,1.1f }; //��
struct APPLE_DATE gApple_Po = { TRUE,3,0,0,-40,45,0.5f,-750,0.9f }; //��

//�X�e�[�^�X�i�[�ϐ�
struct APPLE_DATE gAppleState[APPLE_TYPE];


int gAppleImg[APPLE_TYPE];
int gRandApple;


/*
* �����S�̃f�[�^�i�[
*/
int Apple::AppleSet(void)
{
	
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	if ((gAppleImg[0] = LoadGraph("images/Apple_Red.png")) == -1)return -1;
	if ((gAppleImg[1] = LoadGraph("images/Apple_Blue.png")) == -1)return -1;
	if ((gAppleImg[2] = LoadGraph("images/Apple_Gold.png")) == -1)return -1;
	if((gAppleImg[3] = LoadGraph("images/Apple_Poison.png")) == -1)return -1;

	return 0;
}
	
/**
* �����S�̕`��
*/
void Apple::DrawApple(void){

	DrawRotaGraph(100, 100, 0.25, 0, gAppleImg[0], TRUE, TRUE);

	for (int i = 0; i < APPLE_MAX; i++){
		
		//�����S�̃X�R�A�f�[�^��n��
		//GetDate(gApple[i].score);
		// �v���C���[�Ƃ̓����蔻��
		//PlayerScore();

		// �����S�̕\��
		if (gApple[i].flg == TRUE) {
			DrawRotaGraph(gApple[i].x, gApple[i].y,0.25 ,0, gApple[i].img,TRUE, TRUE);
			gApple[i].y +=  gApple[i].speed * 2;


			//gApple��y���W��1000�ȉ��ɂȂ����Ƃ�����
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//��������������鏈���ɂ�����
			/*if (HitPlayer(&gApple[i], &gPlayer) == TRUE) {
				gApple[i].flg = FALSE;
			}
			*/

			DrawFormatString(0, 0, 0x000000, "speed:%f", gApple[i].speed);
			DrawFormatString(0, 20, 0x000000, "A:%d",gApple[i]);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);


		}	
	}

	//�����֐��̓ǂݍ���
	Apple::CreateApple();

}

/**
* �����S�̐���
**/
int Apple::CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i].type = RandApple();				//
			gApple[i] = gAppleState[gApple[i].type];	//�X�e�[�^�X�̊i�[
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(7) * 125 + 50;
			gApple[i].flg = TRUE;
			return TRUE;	//����
		}
	}
	return FALSE;	//���s
}  

/**
* �����S�̏o����
*/
int Apple::RandApple()
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


