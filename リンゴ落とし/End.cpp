#include "End.h"

/****************************************
*@•Ï”‚ÌéŒ¾
*****************************************/
int EndBackImg;			// ”wŒi‰æ‘œ

/****************************************
* ƒGƒ“ƒh‰æ–Ê•`‰æ
*****************************************/
int DrawEnd(void) {

	// ”wŒi‰æ‘œ‚Ì“Ç
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// ‰æ‘œ‚Ì•\¦
	DrawGraph(0, 0, EndBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(500, 10, 0xffffff, "END");

}