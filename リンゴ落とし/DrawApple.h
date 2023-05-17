#pragma once

#define APPLE_MAX  10	//�����S�̍ő吶����
#define APPLE_TYPE  4		//�����S�̎��
#define APPLE_SIZE  400

///******************************************
//* �\���̂̐錾
//******************************************/
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

/*
class Apple_Date
{
public:
	int flg;		//�t���O
	int type;		//���
	int img;		//�摜�\���p
	float x, y, r;		//���W�A���a
	float speed;		//�������x
	int score;		//�X�R�A���Z
	float size;		//�����蔻��̔{��
};
*/

class Apple
{
private:
	int gApple[APPLE_MAX];
	int gAppleImg[APPLE_TYPE];

public:

	struct APPLE_DATE {
		int flg;		//�t���O
		int type;		//���
		int img;		//�摜�\���p
		float x, y, r;		//���W�A���a
		float speed;		//�������x
		int score;		//�X�R�A���Z
		float size;		//�����蔻��̔{��
	};

	int gRandApple;

	//�����S�̐���
	int CreateApple(void);
	int AppleSet(void);
	void DrawApple(void);
	int RandApple(void);

};
