#include "DxLib.h"
#include "UIscore.h"

//int gBackImg;

/*****************
*スコア表示      *
*****************/
void uiscore(int gamemode)
{
	DrawBox(1000, 0, 1280, 720, 0xe0ffe0, TRUE);
	SetFontSize(50);
	DrawString(1080, 10, "TIME", 0x2E8B57);
	//gamemode = 8;
	DrawString(1070, 300, "取得数", 0x2E8B57);

}