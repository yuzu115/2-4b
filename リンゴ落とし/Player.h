#pragma once
class Player
{
private:
		int flg;       // �g�p�t���O
		float x, y;      // ���W
		float w, h;      // ���A����
		float speed;     // �ړ����x

	// �����S�̍��W
	static float ax, ay, ar;

	static float mx0, mx1, my0, my1;

	int LFlg = 0;
	int RFlg = 0;

	int gPlayerImg[5]; // �w�i�摜

public:

	void PlayerInit(void);                            // �v���C���[������
	void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
	//void GetApple(float ax0, float ay0, float ar0);         // �����S�̍��W��ϐ��Ɋi�[
	int HitPlayer(Apple::APPLE_DATE* a);                          // �����S�ƃv���C���[�̓����蔻��
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