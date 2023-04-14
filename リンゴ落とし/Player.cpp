#include"DxLib.h"
#include <math.h>
#include"Player.h"


/******************************************
 * �萔�̐錾
 ******************************************/
 // �v���C���[�̏����l�̒萔
const int PLAYER_POS_X  = 640;  // X���W 
const int PLAYER_POS_Y  = 600;  // Y���W 
const int PLAYER_WIDTH  = 1000; // ��
const int PLAYER_HEIGHT = 0;    // ����
const int PLAYER_SPEED  = 2;    // �ړ����x

/******************************************
 * �\���̂̐錾
 ******************************************/
 // �v���C���[�̍\����
struct PLAYER
{
	int flg;       // �g�p�t���O
	int x, y;      // ���W
	int w, h;      // ����
	int speed;     // �ړ����x

};

// �v���C���[�̕ϐ��錾
struct PLAYER gPlayer;

/******************************************
 * �v���C���[������
 ******************************************/
// �v���C���[�̏����ݒ�
void PlayerInit(void)
{
	gPlayer.flg = TRUE;         
	gPlayer.x = PLAYER_POS_X;   
	gPlayer.y = PLAYER_POS_Y;   
	gPlayer.w = PLAYER_WIDTH;   
	gPlayer.h = PLAYER_HEIGHT;
	gPlayer.speed = PLAYER_SPEED;
}

/*************************************
 * �v���C���[�̈ړ�
 *************************************/
void PlayerControl(int oldkey,int gamemode)
{
	// �v���C���[���\��
	DrawCircle(gPlayer.x, PLAYER_POS_Y, 50, 0xffffff, TRUE);

	// ���E�ړ�
	if (gPlayer.flg == TRUE)
	{
		// ���ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���삷��
		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
		{
			DrawCircle(gPlayer.x, PLAYER_POS_Y, 50, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed * 2;
		}
		// �����F���X�e�B�b�N����̂�
		else if (oldkey & PAD_INPUT_LEFT)
		{
			gPlayer.x -= gPlayer.speed;
		}
		

		// �E�ړ�
		// �_�b�V���FA�{�^�����������܂܍��X�e�B�b�N���삷��
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			DrawCircle(gPlayer.x, PLAYER_POS_Y, 50, 0xff0000, TRUE);
			gPlayer.x += gPlayer.speed * 2;
		}
		// �����F���X�e�B�b�N����̂�
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			gPlayer.x += gPlayer.speed;
		}
		
	}

	// ��ʂ��͂ݏo���Ȃ��悤�ɂ���
	// �E
	if (gPlayer.x > PLAYER_WIDTH)
	{
		gPlayer.x = PLAYER_WIDTH;
	}
	// ��
	if (gPlayer.x < 50)
	{
		gPlayer.x = 50;
	}

}
/*************************************
 * �v���C���[�̓����蔻��
 *************************************/
void HitBoxPlayer(PLAYER* p)
{
	// x,y�͒��S���W�Ƃ���
	// px1,py1 ���� px2,py1 �E��
	int px1 = (p->x - (p->w / 2)) + 5;
	int py1 = (p->y - (p->h / 2)) + 5;
	int px2 = (px1 + p->w) - 10;
	int py2 = (py1 + p->h) - 5;

	// ��`�����蔻��͈͕\��(�m�F�p)
	DrawBox(px1, py1, px2, py2, 0xff0000, TRUE);

}
