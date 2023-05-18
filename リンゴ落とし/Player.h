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
	// �����S�̍��W
	static float ax, ay, ar;

	static float mx0, mx1, my0, my1;

	int LFlg = 0;
	int RFlg = 0;

	int gPlayerImg[5]; // �w�i�摜

public:

	typedef struct
	{
		int flg;       // �g�p�t���O
		float x, y;      // ���W
		float w, h;      // ���A����
		float speed;     // �ړ����x
	}PLAYER;

	struct PLAYER gPlayer;


	void PlayerInit(void);                            // �v���C���[������
	void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
	//void GetApple(float ax0, float ay0, float ar0);         // �����S�̍��W��ϐ��Ɋi�[

	int HitPlayer(APPLE_DATE* a);                          // �����S�ƃv���C���[�̓����蔻��
	float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z
	int LoadPlayerImg(void);       // �摜�Ǎ�
};

// ���+���̌v�Z
float Player::Pythagorean(float px, float py, float ax, float ay)
{
	float dx, dy, r;

	dx = px - ax;
	dy = py - ay;

	r = (dx * dx) + (dy * dy);

	return (r);

}