#include "Help.h"

/****************************************
*@•Ï”‚ÌéŒ¾
*****************************************/
int HelpBackImg;		// ”wŒi‰æ‘œ

int DrawHelp(void) {

	// ”wŒi‰æ‘œ‚Ì“Ç
	if ((HelpBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// ‰æ‘œ‚Ì•\¦
	DrawGraph(0, 0, HelpBackImg, FALSE);

	SetFontSize(40);
	DrawFormatString(500, 10, 0xffffff, "HELP");

	return 0;
}