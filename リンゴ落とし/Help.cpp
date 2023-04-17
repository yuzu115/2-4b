#include "Help.h"

/****************************************
*@•Ï”‚ÌéŒ¾
*****************************************/
int BackImg;		// ”wŒi‰æ‘œ

int DrawHelp(void) {

	// ”wŒi‰æ‘œ‚Ì“Ç
	if ((BackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// ‰æ‘œ‚Ì•\¦
	DrawGraph(0, 0, BackImg, FALSE);

	SetFontSize(40);
	DrawFormatString(500, 10, 0xffffff, "HELP");

	return 0;
}