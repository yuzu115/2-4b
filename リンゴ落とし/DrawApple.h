#pragma once
#ifndef APPLE_H__
#define APPLE_H__

/******************************************
* �萔�̐錾
******************************************/
const int APPLE_MAX = 10;	//�����S�̍ő吶����
const int APPLE_TYPE = 4;		//�����S�̎��
const int APPLE_SIZE = 400;

/******************************************
* �\���̂̐錾
******************************************/
//struct APPLE_DATE {
//	int flg;		//�t���O
//	int type;		//���
//	int img;		//�摜�\���p
//	float x, y, r;		//���W�A���a
//	float speed;		//�������x
//	int score;		//�X�R�A���Z
//	float size;		//�����蔻��̔{��
//};

/******************************************
 * �֐��̃v���g�^�C�v�錾
 ******************************************/
int AppleSet(void);
void DrawApple(void);
int RandApple(void);

class Apple
{
public:
	//�����S�̐���
	static int CreateApple(void);

	struct APPLE_DATE {
		int flg;		//�t���O
		int type;		//���
		int img;		//�摜�\���p
		float x, y, r;		//���W�A���a
		float speed;		//�������x
		int score;		//�X�R�A���Z
		float size;		//�����蔻��̔{��
	};

private:

};

#endif