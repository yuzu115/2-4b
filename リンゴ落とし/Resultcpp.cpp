//#include "DxLib.h"
//#include "Result.h"
//#include "Ranking.h"
//
///****************************************
//*�@�ϐ��̐錾
//*****************************************/
//int ResultImg;			// ���U���g�摜
//int g_Score;			// ���݂̃X�R�A
//
////int WaitTime = 0;			// �҂�����
//
///****************************************
//* ���U���g��ʕ`��
//*****************************************/
//int DrawResult(void)
//{
//	// ���U���g�摜�̓Ǎ�
//	if ((ResultImg = LoadGraph("images/Back.png")) == -1) return -1;
//	
//	// ReadRanking();		//�����L���O�f�[�^�̓Ǎ�
//
//	//�^�C���̉��Z����(180f�ȏ�o�ߌ�)����ʑJ��
//	//if (++WaitTime > 900)
//	// �X�R�A�������L���O�̍ŉ��ʂ̒l�ȏ�
//		//if (Ranking[RANK_MAX - 1].score >= g_Score){
//		//	GameMode = 5;			// INPUTNAME
//		//}
//		//else {
//		//	GameMode = 3;		// RANKING
//		// }
//		
//	// ���U���g�摜�̕\��
//	DrawGraph(0, 0, ResultImg, FALSE);
//
//	SetFontSize(30);
//	DrawFormatString(400, 300, 0x000000, "�ԃ����S�F%3d\n");
//	DrawFormatString(400, 340, 0x000000, "�����S�F%3d\n");
//	DrawFormatString(400, 380, 0x000000, "�������S�F%3d\n");
//	DrawFormatString(400, 420, 0x000000, "�Ń����S�F%3d\n");
//	DrawFormatString(400, 460, 0x000000, "�X�R�A�@�F%3d\n");
//
//	return 0;
//}