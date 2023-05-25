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
//void DrawResult(RankingData Ranking[],int& GameMode);		// ���U���g��ʕ`��
//void GetAppScore(Apple::AppScore* as);
//int LoadResultImages(void);			// ���U���g�摜�Ǎ�

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
	void GetAppScore(Apple::AppScore* as);
	void DrawResult(RankingData Ranking[], int& GameMode);		// ���U���g��ʕ`��
	int LoadResultImages(void);									// ���U���g�摜�Ǎ�
};

#endif // !RESULT_H__