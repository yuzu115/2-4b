#include "DxLib.h"
#include "Ranking.h"
#include "Keyboard.h"
#include"DrawApple.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int RankingImg;			// �����L���O�摜

int Ranking;

//�����L���O�f�[�^�̕ϐ��錾
// RankingData Ranking[RANK_MAX];

/****************************************
* �����L���O��ʕ`��
*****************************************/
void DrawRanking(XINPUT_STATE input, RankingData Ranking[], int& Button_flg, int& GameMode)
{

	if (input.Buttons[XINPUT_BUTTON_A] == 0) {
		Button_flg = FALSE;
	}

	// A�{�^���ŃX�^�[�g��ʂɖ߂�
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 0;		// TITLE
	}

	//�����L���O�摜�\��
	DrawGraph(0, 0, RankingImg, FALSE);

	// �����L���O�ꗗ��\��
	SetFontSize(60);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(260, 180 + i * 85, 0x000000, "%2d %-10s %10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

}

/***********************************************
 * �����L���O���בւ�
 ***********************************************/
void SortRanking(RankingData Ranking[])
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
int  SaveRanking(RankingData Ranking[])
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
int ReadRanking(RankingData Ranking[])
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

/******************************************
* �����L���O���͏���
******************************************/
void InputName(RankingData Ranking[],XINPUT_STATE input,int& GameMode,int& Button_flg)
{
	Apple app;
	
	if (KeyBoard_PushB(input, Ranking[RANK_MAX - 1].name, Button_flg) == 1)
	{
		Ranking[RANK_MAX - 1].score = app.GetScore();   // �����L���O�f�[�^10�ԖڂɃX�R�A��o�^
		SortRanking(Ranking);
		SaveRanking(Ranking);
		GameMode = 3;                                // �Q�[�����[�h�̕ύX
	}
	else //���͊������Ă��Ȃ���
	{
		KeyBoard_Draw();                             //�L�[�{�[�h�̕`��
		KeyBoard_Update(input,Button_flg);                        //�L�[�{�[�h�̍X�V�E����
	}

}


/*************************************
 * �����L���O�摜�Ǎ�
 *************************************/
int LoadRankingImages(void)
{
	// �����L���O�摜�̓Ǎ�
	if ((RankingImg = LoadGraph("images/ranking.png")) == -1) return -1;

	return 0;
}