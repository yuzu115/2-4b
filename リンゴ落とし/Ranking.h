#pragma once
#include "DxLib.h"

//�����L���O��ʂ݂̂Ŏg���ϐ��E�֐��̐錾�������ɏ����܂�

//�摜�ϐ��������ɏ����Ă�������

/*****************************************
*�@�\����
******************************************/
//�����L���O�f�[�^�\����
struct RankingData {
	int no;
	char name[11];			// 10Byte
	long score;
};

int LoadImages(void);			// �摜�Ǎ�
void DrawRanking(int g_KeyFlg, int& GameMode);		// �����L���O��ʕ`�揈��
int ReadRanking(void);			// �����L���O�f�[�^�̓Ǎ�

//void InputRanking(int g_KeyFlg, int& GameMode);			// �����L���O���͏���

void SortRanking(void);			// �����L���O���בւ�
int SaveRanking(void);			// �����L���O�f�[�^�̕ۑ�