#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__

/******************************************
 * �֐��̃v���g�^�C�v�錾
 ******************************************/
void PlayerInit(void);                            // �v���C���[������
void PlayerControl(int oldkey, int gamemode);     // �v���C���[����
void GetApple(float ax0, float ay0, float ar0);         // �����S�̍��W��ϐ��Ɋi�[
void HitPlayer(void);                            // �����S�ƃv���C���[�̓����蔻��
float Pythagorean(float px, float py, float ax, float ay);  // �s�^�S���X�̒藝�̌v�Z
int LoadPlayerImg(void);       // �摜�Ǎ�
#endif