#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"

int gAppleImg[APPLE_TYPE];
int gRandApple;

//�����S�̕ϐ�
Apple::APPLE_DATE gApple[APPLE_MAX];
Apple::APPLE_DATE gNewApple[APPLE_MAX];
Apple::APPLE_DATE gNextApple[APPLE_MAX];



//�X�e�[�^�X�i�[�ϐ�
Apple::APPLE_DATE gAppleState[APPLE_TYPE];

Apple::Apple()
{
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	gAppledata.flg = FALSE;		//�t���O
	gAppledata.type = 0;		//���
	gAppledata.img = 0;		//�摜�\���p
	gAppledata.x = 0;
	gAppledata.y = 0;
	gAppledata.r = 0;		//���W�A���a
	gAppledata.speed = 0;		//�������x
	gAppledata.score = 0;		//�X�R�A���Z
	gAppledata.size = 0;		//�����蔻��̔{��
	
	gRandApple = 0;

}

Apple::~Apple()
{

}
/*
* �����S�̃f�[�^�i�[
*/
int Apple::AppleSet(void)
{
	
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

	Player p;

	//�����֐��̓ǂݍ���
	Apple::CreateApple();

	for (int i = 0; i < APPLE_MAX; i++){

		// �����S�̕\��
		if (gApple[i].flg == TRUE) {
			DrawRotaGraph(gApple[i].x, gApple[i].y,0.25 ,0, gApple[i].img,TRUE, TRUE);
			gApple[i].y +=  gApple[i].speed * 2;
			p.GetApple(&gApple[i]);

			//gApple��y���W��1000�ȉ��ɂȂ����Ƃ�����
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//��������������鏈���ɂ�����
			if (p.HitPlayer() == TRUE) {
				gApple[i].flg = FALSE;
			}
			
			DrawFormatString(0, 0, 0x000000, "speed:%f", gApple[i].speed);
			DrawFormatString(0, 20, 0x000000, "A:%d",gApple[i]);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);


		}	
	}
}

/**
* �����S�̐���
**/
int Apple::CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {

			//�X�e�[�^�X�̊i�[
			gApple[i] = gNewApple[i];
			gNewApple[i] = gNextApple[i] = gAppleState[RandApple()];

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


