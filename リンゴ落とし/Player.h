#pragma once
class Player
{
private:

    // ��ʃT�C�Y
	const int SCREEN_WIDTH = 1280;   // ��
	const int SCREEN_HEIGHT = 720;    // ����

	 // �v���C���[�̏����l�̒萔
	const int PLAYER_POS_X = 600;  // X���W 
	const int PLAYER_POS_Y = 527;  // Y���W 
	const int PLAYER_SPEED = 5;    // �ړ����x

public:

    // �v���C���[�̍\����
	struct PLAYER
	{
		int flg;       // �g�p�t���O
		float x, y;      // ���W
		int w, h;      // ���A����
		int speed;     // �ړ����x
	};

	// �v���C���[�̕ϐ��錾
	struct PLAYER gPlayer;

	int gPlayerImg[5]; // �w�i�摜

	 // �����S�̍��W
	float ax, ay, ar;

	int LFlg = 0;
	int RFlg = 0;

	void PlayerInit(void);                            // �v���C���[������
	void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
	void GetApple(float ax0, float ay0, float ar0);         // �����S�̍��W��ϐ��Ɋi�[
	void HitPlayer(void);                            // �����S�ƃv���C���[�̓����蔻��
	float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z
	int LoadPlayerImg(void);       // �摜�Ǎ�

};

//#ifndef PLAYER_H__
//#define PLAYER_H__
//
///******************************************
// * �֐��̃v���g�^�C�v�錾
// ******************************************/
//void PlayerInit(void);                            // �v���C���[������
//void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
//void GetApple(float ax0, float ay0, float ar0);         // �����S�̍��W��ϐ��Ɋi�[
//void HitPlayer(void);                            // �����S�ƃv���C���[�̓����蔻��
//float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z
//int LoadPlayerImg(void);       // �摜�Ǎ�
//#endif