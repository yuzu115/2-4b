#pragma once

/******************************************
* �\���̂̐錾
******************************************/
struct APPLE_DATE {
	int flg;		//�t���O
	int type;		//���
	int img;		//�摜�\���p
	float x, y, r;		//���W�A���a
	float speed;		//�������x
	int score;		//�X�R�A���Z
	float size;		//�����蔻��̔{��
};

/******************************************
 * �֐��̃v���g�^�C�v�錾
 ******************************************/


class Apple
{

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

public:
	//�����S�̐���
	int CreateApple(void);
	int AppleSet(void);
	void DrawApple(void);
	int RandApple(void);

};
