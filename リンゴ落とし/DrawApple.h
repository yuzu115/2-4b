#pragma once

#define APPLE_MAX  10	//�����S�̍ő吶����
#define APPLE_TYPE  4		//�����S�̎��
#define APPLE_SIZE  400

class Apple
{
public:
	struct APPLE_DATA {
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
	void AppleHit(APPLE_DATA* a);

private:
	//�e�����S�̃f�[�^
	APPLE_DATA gApple_Rd = { FALSE,0,0,0,-40,45,1,100,1.1f };	//��
	APPLE_DATA gApple_Bl = { FALSE,1,0,0,-40,45,2,200,1.1f }; //��
	APPLE_DATA gApple_Gl = { FALSE,2,0,0,-40,45,3.5f,500,1.1f }; //��
	APPLE_DATA gApple_Po = { FALSE,3,0,0,-40,45,0.5f,-750,0.9f }; //��
};
