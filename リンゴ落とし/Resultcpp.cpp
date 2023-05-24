#include "DxLib.h"
#include "Result.h"
#include "DrawApple.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int ResultBackImg;					// �w�i�摜

int ResultWaitTime = 0;					// �҂�����

int RS;
int BS;
int GS;
int PS;

void GetAppScore(Apple::AppScore* as)
{
	RS = as->r;
	BS = as->b;
	GS = as->g;
	PS = as->p;
}

/****************************************
* ���U���g��ʕ`��
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{
	Apple app;

	LoadResultImages();					// ���U���g�摜�Ǎ�

	// ReadRanking(Ranking);			//�����L���O�f�[�^�̓Ǎ�

	//�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
	if (++ResultWaitTime > 180) {
		// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		if (Ranking[RANK_MAX - 1].score <= app.GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

		
	// ���U���g�摜�̕\��
	DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(50);
	DrawFormatString(410, 180, 0x000000, "�ԃ����S : %3d �R\n",RS);
	DrawFormatString(410, 240, 0x000000, "�����S : %3d �R\n",BS);
	DrawFormatString(410, 300, 0x000000, "�������S : %3d �R\n",GS);
	DrawFormatString(410, 360, 0x000000, "�Ń����S : %3d �R\n",PS);
	DrawFormatString(410, 500, 0x000000, "�X�R�A   : %5d\n",app.GetScore());

}

/****************************************
* ���U���g�摜�Ǎ�
*****************************************/
int LoadResultImages(void)
{
	// �w�i��ʂ̓Ǎ�
	if ((ResultBackImg = LoadGraph("images/result.png")) == -1) return -1;

	return 0;
}