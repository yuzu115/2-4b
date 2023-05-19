#include "DxLib.h"
#include "Result.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int ResultBackImg;					// �w�i�摜
int g_Score = 0;						// ���݂̃X�R�A

int ResultWaitTime = 0;					// �҂�����

RESULT::RESULT()
{
	ResultBackImg = 0;					// �w�i�摜
	g_Score = 0;						// ���݂̃X�R�A
	ResultWaitTime = 0;					// �҂�����
}

RESULT::~RESULT()
{

}

void RESULT::DrawResult(RankingData Ranking[], int& GameMode)
{
	LoadResultImages();					// ���U���g�摜�Ǎ�

	// ReadRanking(Ranking);			//�����L���O�f�[�^�̓Ǎ�

	//�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
	if (++ResultWaitTime > 180) {
		// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		if (Ranking[RANK_MAX - 1].score >= g_Score) {
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
	DrawFormatString(400, 460, 0x000000, "�X�R�A�@�F%3d\n");

}



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
		if (Ranking[RANK_MAX - 1].score >= g_Score) {
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
	DrawFormatString(400, 460, 0x000000, "�X�R�A�@�F%3d\n");

}

/****************************************
* �t���[���̌o��
*****************************************/
//int Progress(int& Count,int& on,int& off) {
//
//	if (Count <= 120) {
//
//		//120�b���܂ŁA20f���o�œ_��
//		if (on == 20) {
//			off = 0;
//
//			DrawBox(0, 0, 40, 40, 0x000000, TRUE);
//			// �v���C���[���\��(��)
//			//DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
//
//			return off;
//
//		}
//
//		if (off == 20) {
//			on = 0;
//			DrawBox(0, 0, 40, 40, 0xff0000, FALSE);
//
//			//DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x000000, TRUE);
//
//			return on;
//		}
//
//	}
//	
//}


/****************************************
* ���U���g�摜�Ǎ�
*****************************************/
int LoadResultImages(void)
{
	// �w�i��ʂ̓Ǎ�
	if ((ResultBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}