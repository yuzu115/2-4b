#include "DxLib.h"
#include "Result.h"
#include "DrawApple.h"
#include "Player.h"
#include"Keyboard.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int ResultBackImg;					// �w�i�摜

int ResultWaitTime = 0;					// �҂�����

int RC;			// �ԃ����S�̊l����
int BC;			// �����S�̊l����
int GC;			// �������S�̊l����
int PC;			// �Ń����S�̊l����

Apple appi;
Player Playi;

void GetAppScore(Apple::AppScore* as)
{
	RC = as->r;
	BC = as->b;
	GC = as->g;
	PC = as->p;
}

/****************************************
* ���U���g��ʕ`��
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{

	Playi.Init(1);
	appi.AppleInit(1); 
	KeyBoardInit();

	//�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
	if (++ResultWaitTime > 180) {
		// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		if (Ranking[RANK_MAX - 1].score <= appi.GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}
		ResultWaitTime = 0;

	}

	// ���U���g�摜�̕\��
	DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(50);
	DrawFormatString(410, 180, 0x000000, "�ԃ����S : %3d �R\n",RC);
	DrawFormatString(410, 240, 0x000000, "�����S : %3d �R\n",BC);
	DrawFormatString(410, 300, 0x000000, "�������S : %3d �R\n",GC);
	DrawFormatString(410, 360, 0x000000, "�Ń����S : %3d �R\n",PC);
	DrawFormatString(410, 500, 0x000000, "�X�R�A   : %5d\n",appi.GetScore());
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