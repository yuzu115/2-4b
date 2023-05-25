#include "DxLib.h"
#include "Result.h"

Result::Result()
{
	ResultBackImg = 0;					// �w�i�摜
	ResultWaitTime = 0;					// �҂�����
	RC = 0;			// �ԃ����S�̊l����
	BC = 0;			// �����S�̊l����
	GC = 0;			// �������S�̊l����
	PC = 0;			// �Ń����S�̊l����
}

Result::~Result()
{

}

/****************************************
* �����S�̊l�������擾
*****************************************/
void Result::GetAppScore(Apple::AppScore* as)
{
	RC = as->r;
	BC = as->b;
	GC = as->g;
	PC = as->p;
}

/****************************************
* ���U���g��ʕ`��
*****************************************/
void Result::DrawResult(RankingData Ranking[], int& GameMode)
{
	Apple app;

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
	DrawFormatString(410, 180, 0x000000, "�ԃ����S : %3d �R\n",RC);
	DrawFormatString(410, 240, 0x000000, "�����S : %3d �R\n",BC);
	DrawFormatString(410, 300, 0x000000, "�������S : %3d �R\n",GC);
	DrawFormatString(410, 360, 0x000000, "�Ń����S : %3d �R\n",PC);
	DrawFormatString(410, 500, 0x000000, "�X�R�A   : %5d\n",app.GetScore());
}

/****************************************
* ���U���g�摜�Ǎ�
*****************************************/
int Result::LoadResultImages(void)
{
	// �w�i��ʂ̓Ǎ�
	if ((ResultBackImg = LoadGraph("images/result.png")) == -1) return -1;

	return 0;
}