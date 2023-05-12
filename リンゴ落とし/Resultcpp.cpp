//#include "DxLib.h"
//#include "Result.h"
//#include "Ranking.h"
//
///****************************************
//*　変数の宣言
//*****************************************/
//int ResultImg;			// リザルト画像
//int g_Score;			// 現在のスコア
//
////int WaitTime = 0;			// 待ち時間
//
///****************************************
//* リザルト画面描画
//*****************************************/
//int DrawResult(void)
//{
//	// リザルト画像の読込
//	if ((ResultImg = LoadGraph("images/Back.png")) == -1) return -1;
//	
//	// ReadRanking();		//ランキングデータの読込
//
//	//タイムの加算処理(180f以上経過後)＆画面遷移
//	//if (++WaitTime > 900)
//	// スコアがランキングの最下位の値以上
//		//if (Ranking[RANK_MAX - 1].score >= g_Score){
//		//	GameMode = 5;			// INPUTNAME
//		//}
//		//else {
//		//	GameMode = 3;		// RANKING
//		// }
//		
//	// リザルト画像の表示
//	DrawGraph(0, 0, ResultImg, FALSE);
//
//	SetFontSize(30);
//	DrawFormatString(400, 300, 0x000000, "赤リンゴ：%3d\n");
//	DrawFormatString(400, 340, 0x000000, "青リンゴ：%3d\n");
//	DrawFormatString(400, 380, 0x000000, "金リンゴ：%3d\n");
//	DrawFormatString(400, 420, 0x000000, "毒リンゴ：%3d\n");
//	DrawFormatString(400, 460, 0x000000, "スコア　：%3d\n");
//
//	return 0;
//}