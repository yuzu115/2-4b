#include "DxLib.h"
#include "Result.h"
//#include "Ranking.h"

/****************************************
*�@�ϐ��̐錾
*****************************************/
int ResultImg;			// ���U���g�摜

///****************************************
//* �摜�Ǎ�
//*****************************************/
//int LoadImages(void)
//{
//	// ���U���g�摜�̓Ǎ�
//	if ((ResultImg = LoadGraph("images/Back.png")) == -1) return -1;
//
//	return 0;
//
//}

/****************************************
* ���U���g��ʕ`�揈��
*****************************************/
void DrawResult(int& GameMode)
{
	// LoadImages();

	////�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
	//if (++g_WaitTime > 900)
		//// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
		//if (Ranking[RANK_MAX - 1].score >= g_Score){
		//	GameMode = 5;			// ���O���͂�
		//}
		//else {
		//	GameMode = 3;		// �����L���O��ʂ�
		//}
	//}

	SetFontSize(30);
	DrawFormatString(300, 300, 0x000000, "�ԃ����S�F%3d0\n");
	DrawFormatString(300, 340, 0x000000, "�����S�F%3d0\n");
	DrawFormatString(300, 380, 0x000000, "�������S�F%3d0\n");
	DrawFormatString(300, 420, 0x000000, "�Ń����S�F%3d0\n");
	DrawFormatString(300, 460, 0x000000, "�X�R�A�F%3d0\n");

}