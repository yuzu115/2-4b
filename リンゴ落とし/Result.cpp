#include "DxLib.h"
#include "Result.h"
#include "DrawApple.h"

/****************************************
*@ÏÌéŸ
*****************************************/
int ResultBackImg;					// wiæ

int ResultWaitTime = 0;					// ÒżÔ

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
* UgæÊ`æ
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{
<<<<<<<< HEAD:ăȘăłăŽèœăšă/Result.cpp
	//LoadResultImages();					// UgæÇ
========
	Apple app;

	LoadResultImages();					// UgæÇ
>>>>>>>> origin/Cmarge:ăȘăłăŽèœăšă/Resultcpp.cpp

	// ReadRanking(Ranking);			//LOf[^ÌÇ

	//^CÌÁZ(180fÈăoßă)æÊJÚ
<<<<<<<< HEAD:ăȘăłăŽèœăšă/Result.cpp
	//if (++WaitTime > 900)
	// XRAȘLOÌĆșÊÌlÈă
		//if (Ranking[RANK_MAX - 1].score >= g_Score){
		//	//GameMode = 5;				// INPUTNAME
		//}
		//else {
		//	GameMode = 3;				// RANKING
		// }
========
	if (++ResultWaitTime > 180) {
		// XRAȘLOÌĆșÊÌlÈă
		if (Ranking[RANK_MAX - 1].score <= app.GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

>>>>>>>> origin/Cmarge:ăȘăłăŽèœăšă/Resultcpp.cpp
		
	// UgæÌ\Š
	//DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(30);
<<<<<<<< HEAD:ăȘăłăŽèœăšă/Result.cpp
	DrawFormatString(400, 300, 0xffffff, "ÔSF%3d\n");
	DrawFormatString(400, 340, 0x000000, "ÂSF%3d\n");
	DrawFormatString(400, 380, 0x000000, "àSF%3d\n");
	DrawFormatString(400, 420, 0x000000, "ĆSF%3d\n");
	DrawFormatString(400, 460, 0x000000, "XRA@F%3d\n");
========
	DrawFormatString(400, 300, 0x000000, "ÔSF%3d\n",RS);
	DrawFormatString(400, 340, 0x000000, "ÂSF%3d\n",BS);
	DrawFormatString(400, 380, 0x000000, "àSF%3d\n",GS);
	DrawFormatString(400, 420, 0x000000, "ĆSF%3d\n",PS);
	DrawFormatString(400, 460, 0x000000, "XRA@F%3d\n",app.GetScore());
>>>>>>>> origin/Cmarge:ăȘăłăŽèœăšă/Resultcpp.cpp

}

/****************************************
* UgæÇ
*****************************************/
int LoadResultImages(void)
{
	// wiæÊÌÇ
	if ((ResultBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}