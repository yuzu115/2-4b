#pragma once

#define APPLE_MAX  10	//�����S�̍ő吶����
#define APPLE_TYPE  4		//�����S�̎��
#define APPLE_SIZE  400

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

	/******************************************
	* �֐��̃v���g�^�C�v�錾
	 ******************************************/
	Apple();
	~Apple();
	//�����S�̐���
	int CreateApple(void);
	int AppleSet(void);
	void DrawApple(void);
	int RandApple(void);

private:
	//�e�����S�̃f�[�^
	APPLE_DATE gApple_Rd = { TRUE,0,0,0,-40,45,1,100,1.1f };	//��
	APPLE_DATE gApple_Bl = { TRUE,1,0,0,-40,45,2,200,1.1f }; //��
	APPLE_DATE gApple_Gl = { TRUE,2,0,0,-40,45,3.5f,500,1.1f }; //��
	APPLE_DATE gApple_Po = { TRUE,3,0,0,-40,45,0.5f,-750,0.9f }; //��
};
