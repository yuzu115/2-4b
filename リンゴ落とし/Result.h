#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

//���U���g��ʂ݂̂Ŏg���ϐ��E�֐��̐錾�������ɏ����܂�

//�摜�ϐ��������ɏ����Ă�������

/*****************************************
*�@�v���g�^�C�v�錾
******************************************/
void DrawResult(RankingData Ranking[],int& GameMode);		// ���U���g��ʕ`��
void GetAppScore(Apple::AppScore* as);
int LoadResultImages(void);			// ���U���g�摜�Ǎ�

#endif // !RESULT_H__