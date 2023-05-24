#include "DxLib.h"
#include "Result.h"
#include "DrawApple.h"

/****************************************
*@•Ï”‚ÌéŒ¾
*****************************************/
int ResultBackImg;					// ”wŒi‰æ‘œ

int ResultWaitTime = 0;					// ‘Ò‚¿ŠÔ

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
* ƒŠƒUƒ‹ƒg‰æ–Ê•`‰æ
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{
<<<<<<<< HEAD:ãƒªãƒ³ã‚´è½ã¨ã—/Result.cpp
	//LoadResultImages();					// ƒŠƒUƒ‹ƒg‰æ‘œ“Ç
========
	Apple app;

	LoadResultImages();					// ƒŠƒUƒ‹ƒg‰æ‘œ“Ç
>>>>>>>> origin/Cmarge:ãƒªãƒ³ã‚´è½ã¨ã—/Resultcpp.cpp

	// ReadRanking(Ranking);			//ƒ‰ƒ“ƒLƒ“ƒOƒf[ƒ^‚Ì“Ç

	//ƒ^ƒCƒ€‚Ì‰ÁZˆ—(180fˆÈãŒo‰ßŒã)•‰æ–Ê‘JˆÚ
<<<<<<<< HEAD:ãƒªãƒ³ã‚´è½ã¨ã—/Result.cpp
	//if (++WaitTime > 900)
	// ƒXƒRƒA‚ªƒ‰ƒ“ƒLƒ“ƒO‚ÌÅ‰ºˆÊ‚Ì’lˆÈã
		//if (Ranking[RANK_MAX - 1].score >= g_Score){
		//	//GameMode = 5;				// INPUTNAME
		//}
		//else {
		//	GameMode = 3;				// RANKING
		// }
========
	if (++ResultWaitTime > 180) {
		// ƒXƒRƒA‚ªƒ‰ƒ“ƒLƒ“ƒO‚ÌÅ‰ºˆÊ‚Ì’lˆÈã
		if (Ranking[RANK_MAX - 1].score <= app.GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

>>>>>>>> origin/Cmarge:ãƒªãƒ³ã‚´è½ã¨ã—/Resultcpp.cpp
		
	// ƒŠƒUƒ‹ƒg‰æ‘œ‚Ì•\¦
	//DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(30);
<<<<<<<< HEAD:ãƒªãƒ³ã‚´è½ã¨ã—/Result.cpp
	DrawFormatString(400, 300, 0xffffff, "ÔƒŠƒ“ƒSF%3d\n");
	DrawFormatString(400, 340, 0x000000, "ÂƒŠƒ“ƒSF%3d\n");
	DrawFormatString(400, 380, 0x000000, "‹àƒŠƒ“ƒSF%3d\n");
	DrawFormatString(400, 420, 0x000000, "“ÅƒŠƒ“ƒSF%3d\n");
	DrawFormatString(400, 460, 0x000000, "ƒXƒRƒA@F%3d\n");
========
	DrawFormatString(400, 300, 0x000000, "ÔƒŠƒ“ƒSF%3d\n",RS);
	DrawFormatString(400, 340, 0x000000, "ÂƒŠƒ“ƒSF%3d\n",BS);
	DrawFormatString(400, 380, 0x000000, "‹àƒŠƒ“ƒSF%3d\n",GS);
	DrawFormatString(400, 420, 0x000000, "“ÅƒŠƒ“ƒSF%3d\n",PS);
	DrawFormatString(400, 460, 0x000000, "ƒXƒRƒA@F%3d\n",app.GetScore());
>>>>>>>> origin/Cmarge:ãƒªãƒ³ã‚´è½ã¨ã—/Resultcpp.cpp

}

/****************************************
* ƒŠƒUƒ‹ƒg‰æ‘œ“Ç
*****************************************/
int LoadResultImages(void)
{
	// ”wŒi‰æ–Ê‚Ì“Ç
	if ((ResultBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}