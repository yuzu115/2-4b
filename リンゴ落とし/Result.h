#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

class Result
{
private:
	int ResultBackImg;			// �w�i�摜
	int ResultWaitTime;			// �҂�����
	int RC;						// �ԃ����S�̊l����
	int BC;						// �����S�̊l����
	int GC;						// �������S�̊l����
	int PC;						// �Ń����S�̊l����

public:
	Result();													// �R���X�g���N�^
	~Result();													// �f�X�g���N�^
	void GetAppScore(Apple::AppScore* as);						// �����S�̊l�������擾���Ă���
	void DrawResult(RankingData Ranking[], int& GameMode);		// ���U���g��ʕ`��
	int LoadResultImages(void);									// ���U���g�摜�Ǎ�
};

#endif // !RESULT_H__