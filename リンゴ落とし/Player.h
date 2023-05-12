#pragma once

#ifndef PLAYER_H__
#define PLAYER_H__

#include "DrawApple.h"

/******************************************
 * �萔�̐錾
 ******************************************/
 // ��ʃT�C�Y
const int SCREEN_WIDTH = 1280;   // ��
const int SCREEN_HEIGHT = 720;    // ����

 // �v���C���[�̏����l�̒萔
const int PLAYER_POS_X = 600;  // X���W 
const int PLAYER_POS_Y = 570;  // Y���W 
const int PLAYER_SPEED = 5;    // �ړ����x

/******************************************
 * �\���̂̐錾
 ******************************************/
 // �v���C���[�̍\����
typedef struct 
{
	int flg;       // �g�p�t���O
	float x, y;      // ���W
	int w, h;      // ���A����
	int speed;     // �ړ����x

}PLAYER;



/******************************************
 * �֐��̃v���g�^�C�v�錾
 ******************************************/
void PlayerInit(void);                            // �v���C���[������
void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
//void GetApple(int ax0, float ay0, int ar0,float size);         // �����S�̍��W��ϐ��Ɋi�[
int HitPlayer(APPLE_DATE *a, PLAYER *p);                        // �����S�ƃv���C���[�̓����蔻��
float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z

#endif