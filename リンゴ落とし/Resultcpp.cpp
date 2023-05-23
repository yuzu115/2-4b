#include "DxLib.h"
#include "Result.h"
#include "DrawApple.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int ResultBackImg;					// �w�i�摜

int ResultWaitTime = 0;					// �҂�����

/****************************************
* ���U���g��ʕ`��
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{
	LoadResultImages();					// ���U���g�摜�Ǎ�

	// ReadRanking(Ranking);			//�����L���O�f�[�^�̓Ǎ�

	//�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
	if (++ResultWaitTime > 180) {
		// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		if (Ranking[RANK_MAX - 1].score <= GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

		
	// ���U���g�摜�̕\��
	DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(30);
	DrawFormatString(400, 300, 0x000000, "�ԃ����S�F%3d\n");
	DrawFormatString(400, 340, 0x000000, "�����S�F%3d\n");
	DrawFormatString(400, 380, 0x000000, "�������S�F%3d\n");
	DrawFormatString(400, 420, 0x000000, "�Ń����S�F%3d\n");
	DrawFormatString(400, 460, 0x000000, "�X�R�A�@�F%3d\n",GetScore());

}

/****************************************
* ���U���g�摜�Ǎ�
*****************************************/
int LoadResultImages(void)
{
	// �w�i��ʂ̓Ǎ�
	if ((ResultBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}