#include "DxLib.h"
#include "UIscore.h"

int gUIAppleImg[3];

/*****************
*スコア表示      *
*****************/
void uiscore(int gamemode)
{
	DrawBox(1000, 0, 1280, 720, 0xe0ffe0, TRUE);
	SetFontSize(50);
	DrawString(1080, 10, "TIME", 0x2E8B57);
	//gamemode = 8;
	//DrawString(1070, 300, "取得数", 0x2E8B57);
	DrawUIApple();
}
/*****************
*画像読み出し    *
*****************/
int LoadAppleImg(void)
{
	if ((gUIAppleImg[0] = LoadGraph("images/apple.png")) == -1)return -1;
	if ((gUIAppleImg[1] = LoadGraph("images/blueapple.png")) == -1)return -1;
	if ((gUIAppleImg[2] = LoadGraph("images/goldapple.png")) == -1)return -1;
	
	return 0;
}

/*****************
*仮表示          *
*****************/
void DrawUIApple(void)
{
	LoadAppleImg();
	DrawExtendGraph(1030, 350, 1080, 400, gUIAppleImg[0], TRUE);
	DrawExtendGraph(1115, 350, 1165, 400, gUIAppleImg[1], TRUE);
	DrawExtendGraph(1200, 350, 1250, 400, gUIAppleImg[2], TRUE);
	
}