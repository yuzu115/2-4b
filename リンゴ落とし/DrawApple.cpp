#include"DxLib.h"
#include"DrawApple.h"

/******************************************
* �萔�̐錾
******************************************/
const int APPLE_MAX = 10;	//�����S�̍ő吶����

/******************************************
* �\���̂̐錾
******************************************/
struct APPLE {
	int flg;		//�t���O
	int type;		//���
	int img;		//�摜�\���p
	int x, y, r;	//���W�A���a
	int speed;		//�������x
	int score;		//�X�R�A���Z
};

struct APPLE gApple[APPLE_MAX];
struct APPLE gApple00 = { TRUE,0,0,0,-40,45,3,0 };

int gAppleImg[4];

int AppleInit(void)
{
	if((gAppleImg[0] = 0xff0000) == -1)return -1;	//�ԃ����S
	if((gAppleImg[1] = 0x00ff00) == -1)return -1;	//�����S
	if((gAppleImg[2] = 0xffff00) == -1)return -1;	//�������S
	if((gAppleImg[3] = 0xff00ff) == -1)return -1;	//�Ń����S
	for (int i = 0; i < APPLE_MAX; i++)
	{
		gApple[i].flg = FALSE;
	}
}

void DrawApple(void){

	AppleInit();

	for (int i = 0; i < APPLE_MAX; i++){
		if (gApple[i].flg == TRUE) {
			DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, gApple[i].img, TRUE);
			gApple[i].y += gApple[i].speed;

			if (gApple[i].y > 500) {
				gApple[i].flg = FALSE;
			}
			DrawFormatString(0, 0, 0x000000, "x:%d", gApple[i].x);
			DrawFormatString(0, 20, 0x000000, "y:%d", gApple[i].y);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "speed:%d", gApple[i].speed);
			DrawFormatString(0, 80, 0x000000, "flg:%d", gApple[i].flg);

		}
	}

	CreateApple();

}

int CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gApple00;
			gApple[i].type = GetRand(3);
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(7) * 100 + 50;
			gApple[i].speed = gApple[i].type + gApple[i].speed * 3;

			return TRUE;
		}

		return FALSE;
	}
}