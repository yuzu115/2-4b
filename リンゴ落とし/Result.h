#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

/*****************************************
*�@�v���g�^�C�v�錾
******************************************/
void GetAppScore(Apple::AppScore* as);						// �����S�̊l�������擾���Ă���
void DrawResult(RankingData Ranking[], int& GameMode);		// ���U���g��ʕ`��
int LoadResultImages(void);									// ���U���g�摜�Ǎ�

#endif // !RESULT_H__