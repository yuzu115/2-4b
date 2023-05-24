#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"
#include"Pause.h"
#include"math.h"
#include"Resalt.h"

int gAppleImg[APPLE_TYPE];
int gRandApple;

int Score;
int DCount;

int Count_R;
int Count_B;
int Count_Go;
int Count_Po;


//�����S�̕ϐ�
Apple::APPLE_DATA gApple[APPLE_MAX];

//�X�e�[�^�X�i�[�ϐ�
Apple::APPLE_DATA gAppleState[APPLE_TYPE];


/*
* �R���X�g���N�^
*/
Apple::Apple()
{
	
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	
	gRandApple = 0;

	gScore.r = 0;
	gScore.b = 0;
	gScore.g = 0;
	gScore.p = 0;

}
/*
* �f�X�g���N�^
*/
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
void Apple::DrawApple(int& Pause_flg){

	Player p;	
	Apple ap;

	//�����֐��̓ǂݍ���
	Apple::CreateApple();

	for (int i = 0; i < APPLE_MAX; i++){

		// �����S�̕\��
		if (gApple[i].flg == TRUE) {

			

			DrawRotaGraph(gApple[i].x, gApple[i].y,0.25 ,0, gApple[i].img,TRUE, TRUE);
			//DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, 0xffffff, TRUE);
			gApple[i].y +=  gApple[i].speed ;
	

			p.GetApple(&gApple[i]);
			GetAppScore(&gScore);

			//gApple��y���W��1000�ȉ��ɂȂ����Ƃ�����
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//��������������鏈���ɂ�����
			if (p.HitPlayer() == TRUE) {
				gApple[i].flg = FALSE;

				Score += gApple[i].score;


				if (gApple[i].type == 0)	gScore.r++;
				if (gApple[i].type == 1) 	gScore.b++;
				if (gApple[i].type == 2) 	gScore.g++;
				if (gApple[i].type == 3)	gScore.p++;

			}

			
			
			DrawFormatString(0, 0, 0x000000, "Score:%d",Score);
			DrawFormatString(0, 20, 0x000000, "Red:%d", gScore.r);
			DrawFormatString(0, 40, 0x000000, "Blue:%d", gScore.b);
			DrawFormatString(0, 60, 0x000000, "Gold:%d", gScore.g);
			DrawFormatString(0, 80, 0x000000, "Count:%d", DCount);

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
			gApple[i] = gAppleState[RandApple()];	//�X�e�[�^�X�̊i�[
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(6) * 125 + 50;

			for (int j = 0; j < APPLE_MAX; j++)
			{
				if (i == j)continue;
				
				if (gApple[i].x == gApple[j].x && gApple[i].type == gApple[i].type)
				{
					if (gApple[i].y < gApple[j].r * 2) {
						gApple[i].y -= 100;
					}
					
				}

			}

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

int Apple::GetScore()
{
	return Score;
}
