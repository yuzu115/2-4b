#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__

/******************************************
 * �֐��̃v���g�^�C�v�錾
 ******************************************/
void PlayerInit(void);     // �v���C���[������
void PlayerControl(int oldkey, int gamemode);  // �v���C���[����
void HitBoxPlayer(void);   // �v���C���[�̓����蔻��

#endif