#include "DxLib.h"
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
* �����L���O��ʕ`��
*****************************************/
int DrawRanking(XINPUT_STATE input, int& Button_flg, int& GameMode)
{
	// �����L���O�摜�̓Ǎ�
	if ((RankingImg = LoadGraph("images/Back.png")) == -1) return -1;

	ReadRanking();		//�����L���O�f�[�^�̓Ǎ�

	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	// A�{�^���ŃX�^�[�g��ʂɖ߂�
	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 0;		// TITLE
	}

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
