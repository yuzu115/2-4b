#include "End.h"

/****************************************
*@ÏÌé¾
*****************************************/
int EndBackImg;			// wiæ

/****************************************
* GhæÊ`æiGh[j
*****************************************/
int DrawEnd(void) {

	// wiæÌÇ
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// æÌ\¦
	DrawGraph(0, 0, EndBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
	
	SetFontSize(40);
	DrawString(100, 310 , "fÞp", 0x000000);
	DrawString(100, 370 , "@BGM@@@ @wwww", 0x000000);
	DrawString(100, 410 , "@SE@@@@@wwwwwwww", 0x000000);

}