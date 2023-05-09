#include "DxLib.h"
#include "infomation.h"
#include "Ranking.h"

/****************************************
*�@�萔�̐錾
*****************************************/
//const int RANK_MAX = 5;			// �����L���O�͏��5�ʂ܂�

/****************************************
*�@�ϐ��̐錾
*****************************************/
int RankingImg;			// �����L���O�摜

//�����L���O�f�[�^�̕ϐ��錾
 RankingData Ranking[RANK_MAX];

/****************************************
* �����L���O��ʕ`�揈��
*****************************************/
int DrawRanking(void)
{
	// �����L���O�摜�̓Ǎ�
	if ((RankingImg = LoadGraph("images/Back.png")) == -1) return -1;

	ReadRanking();		//�����L���O�f�[�^�̓Ǎ�

	//// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
	//if (g_KeyFlg & PAD_INPUT_A) GameMode = 0;		// �^�C�g����ʂ�

	//�����L���O�摜�\��
	DrawGraph(0, 0, RankingImg, FALSE);

	// �����L���O�ꗗ��\��
	SetFontSize(90);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(80, 170 + i * 85, 0x000000, "%2d %-10s %10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	SetFontSize(100);
	DrawFormatString(400, 50, 0x000000, "�����L���O");

	SetFontSize(30);
	DrawFormatString(600, 650, 0x000000, "A�F�^�C�g��");

	return 0;
}

///*****************************************
//*�@�����L���O����(���O����)����
//******************************************/
//void InputName(int g_KeyFlg, int& GameMode)
//{
//	// �����L���O�摜�\��
//	DrawGraph(0, 0, RankingImg, FALSE);
//
//	// �t�H���g�T�C�Y
//	SetFontSize(16);
//
//	// ���O�̓��͎w��������̕`��
//	DrawString(80, 150, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
//	DrawString(80, 170, "���O���p���œ��͂��Ă�������", 0xFFFFFF);
//
//	// ���O�̓���
//	DrawString(80, 200, ">", 0xFFFFFF);
//	DrawBox(90, 195, 200, 220, 0x000055, TRUE);
//	if (KeyInputSingleCharString(90, 200, 10, Ranking[RANK_MAX - 1].name, FALSE) == 1) {
//		Ranking[RANK_MAX - 1].score = g_Score;			// �����L���O�f�[�^��10�ԖڂɃX�R�A��o�^
//		SortRanking();									// �����L���O���בւ�
//		SaveRanking();									// �����L���O�f�[�^�̕ۑ�
//		GameMode = 3;							// �Q�[�����[�h�̕ύX
//	}
//
//}

/***********************************************
 * �����L���O���בւ�
 ***********************************************/
void SortRanking(void)
{
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score <= Ranking[j].score) {
				work = Ranking[i];
				Ranking[i] = Ranking[j];
				Ranking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANK_MAX; i++) {
		Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score > Ranking[j].score) {
				Ranking[j].no++;
			}
		}
	}

}

/***********************************************
 * �����L���O�f�[�^�̕ۑ�
 ***********************************************/
int  SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANK_MAX; i++) {
		fprintf(fp, "%2d %10s %10d\n", Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}

/*************************************
 * �����L���O�f�[�^�ǂݍ���
 *************************************/
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANK_MAX; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &Ranking[i].no, Ranking[i].name, &Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}
