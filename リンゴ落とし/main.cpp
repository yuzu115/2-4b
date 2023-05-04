#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include"FPS.h"

int check;//120f回ったか
int on;//20f回ったか
int off;//20f回ったか

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする


	//ScreenFlipを実行しても垂直同期信号を待たない
		//SetWaitVSyncFlag(FALSE);

	//ループ前にFPS計測を初期化
	Reset_fps();

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{

		//画面の初期化
		ClearDrawScreen();
		
		//今出てるFPSの表示
		display_fps();

	if (check <= 120) {
		
		//120秒たつまで、20f感覚で点滅
		if (on == 20) {
			off = 0;

			DrawBox(0, 0, 40, 40, 0xffffff, TRUE);

		}

		if (off == 20) {
			on = 0;
			DrawBox(0, 0, 40, 40, 0x000000, FALSE);
		}

	}

	//if (check == 121)check = 0;

		//裏画面の内容を表画面に反映する
		ScreenFlip();

		//fpsの計測
		Keisoku_fps();

		//fps固定処理
		wait_fanc();

		if (PAD_INPUT_1) {
			check++;
			on++;
			off++;
		}
		
	}
	DxLib_End();
	return 0;
}

