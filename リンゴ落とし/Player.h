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

	Player();
	~Player();                  
	//void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
	void GetApple(Apple::APPLE_DATA* a);
	int HitPlayer(void);                          // �����S�ƃv���C���[�̓����蔻��
	float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z
	int LoadPlayerImg(void);       // �摜�Ǎ�

	void PlayerXControl(XINPUT_STATE input, int& button_flg, int& Pause_flg);     // �v���C���[����iXInput�j
	//void PlayerXLControl(XINPUT_STATE input, int& Pause_flg);     // �v���C���[����iXInput�j
	void PlayerRan(int rImg);
	void PlayerWalk(int Img);
	int PlayerFlashing(int& Pflg);
};

