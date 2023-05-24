#pragma once
#include"DrawApple.h"
// ��ʃT�C�Y
#define SCREEN_WIDTH  1280   // ��
#define SCREEN_HEIGHT 720    // ����

 // �v���C���[�̏����l�̒萔
#define PLAYER_POS_X  600  // X���W 
#define PLAYER_POS_Y  527  // Y���W 
#define PLAYER_SPEED  5    // �ړ����x

class Player
{
private:
	typedef struct
	{
		int flg;       // �g�p�t���O
		float x, y;      // ���W
		float w, h;      // ���A����
		float speed;     // �ړ����x
	}PLAYER;

	PLAYER gPlayer;

public:

/******************************************
 * �֐��̃v���g�^�C�v�錾
 ******************************************/
	Player();
	~Player();                  
	void PlayerControl(XINPUT_STATE input, int gamemode,int Pause_flg);     // �v���C���[����
	void GetApple(Apple::APPLE_DATA* a);
	int HitPlayer(void);                          // �����S�ƃv���C���[�̓����蔻��
	float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z
	int LoadPlayerImg(void);       // �摜�Ǎ�

	void PlayerXControl(XINPUT_STATE input, int& button_flg);     // �v���C���[����iXInput�j
	int PlayerFlashing(int& Count, int& on, int& off);	//�v���C���[�_�ŏ���
	void PlayerWalk(int wImg);		//�����摜�؂�ւ�����
	void PlayerRan(int rImg);		//����摜�؂�ւ�����
};

