#pragma once

#ifndef RANKING_H__
#define RANKING_H__

//�����L���O��ʂ݂̂Ŏg���ϐ��E�֐��̐錾�������ɏ����܂�

//�摜�ϐ��������ɏ����Ă�������

/*****************************************
*�@�}�N����`
******************************************/
#define RANK_MAX (5)			// �����L���O�͏��5�ʂ܂�
#define NAME_MAX (11)			// ���O�̃T�C�Y

/*****************************************
*�@�^��`
******************************************/
//�����L���O�f�[�^
typedef struct
{
	int no;						// ����
	char name[NAME_MAX];		// ���O�@10Byte
	long score;					// �X�R�A
} RankingData;

/*****************************************
*�@�v���g�^�C�v�錾
******************************************/
//int DrawRanking(int g_KeyFlg, int& GameMode);		// �����L���O��ʕ`�揈��
//int ReadRanking(void);								// �����L���O�f�[�^�̓Ǎ�
//
////void InputRanking(int g_KeyFlg, int& GameMode);		// �����L���O���͏���
//
//void SortRanking(void);			// �����L���O���בւ�
//int SaveRanking(void);			// �����L���O�f�[�^�̕ۑ�
//
///*****************************************
//*�@extern�錾
//******************************************/
////�����L���O�f�[�^�̕ϐ��錾
//extern RankingData Ranking[RANK_MAX];			// Ranking��Result�Ŏg�p
//
#endif // !RANKING_H__