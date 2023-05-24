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
<<<<<<<< HEAD:リンゴ落とし/Result.cpp
	//LoadResultImages();					// ���U���g�摜�Ǎ�
========
	Apple app;

	LoadResultImages();					// ���U���g�摜�Ǎ�
>>>>>>>> origin/Cmarge:リンゴ落とし/Resultcpp.cpp

	// ReadRanking(Ranking);			//�����L���O�f�[�^�̓Ǎ�

	//�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
<<<<<<<< HEAD:リンゴ落とし/Result.cpp
	//if (++WaitTime > 900)
	// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		//if (Ranking[RANK_MAX - 1].score >= g_Score){
		//	//GameMode = 5;				// INPUTNAME
		//}
		//else {
		//	GameMode = 3;				// RANKING
		// }
========
	if (++ResultWaitTime > 180) {
		// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		if (Ranking[RANK_MAX - 1].score <= app.GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

>>>>>>>> origin/Cmarge:リンゴ落とし/Resultcpp.cpp
		
	// ���U���g�摜�̕\��
	//DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(30);
<<<<<<<< HEAD:リンゴ落とし/Result.cpp
	DrawFormatString(400, 300, 0xffffff, "�ԃ����S�F%3d\n");
	DrawFormatString(400, 340, 0x000000, "�����S�F%3d\n");
	DrawFormatString(400, 380, 0x000000, "�������S�F%3d\n");
	DrawFormatString(400, 420, 0x000000, "�Ń����S�F%3d\n");
	DrawFormatString(400, 460, 0x000000, "�X�R�A�@�F%3d\n");
========
	DrawFormatString(400, 300, 0x000000, "�ԃ����S�F%3d\n",RS);
	DrawFormatString(400, 340, 0x000000, "�����S�F%3d\n",BS);
	DrawFormatString(400, 380, 0x000000, "�������S�F%3d\n",GS);
	DrawFormatString(400, 420, 0x000000, "�Ń����S�F%3d\n",PS);
	DrawFormatString(400, 460, 0x000000, "�X�R�A�@�F%3d\n",app.GetScore());
>>>>>>>> origin/Cmarge:リンゴ落とし/Resultcpp.cpp

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