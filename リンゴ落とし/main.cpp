#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include"FPS.h"

int check;//120f回ったか
int on;//20f回ったか
int off;//20f回ったか

/*
*四角形左上の座標
*x1に+40で右上の座標
* Y1に+40で左下の座標
//*/
//int x1 = 0;//四角形左上のx座標
//int Y1 = 0;//四角形左上のy座標
////何故かy1だと変数宣言ができなかったのでY１で宣言してます
//
//int x2,y2 = 0;//四角形左下のx,y座標


float x1, Y1 = 0;
float x2, y2 = 0;

float ip = 0;//内積
float cp = 0;//外積

//動く四角形の面積
float m = 0;

float kx, ky = 0;

float a,b,c = 0;//四角形左上の座標計算用 //青
float a2, b2, c2 = 0;//四角形右下の座標計算用 //緑

int a3, b3, c3 = 0;//四角形右上の座標計算用 //オレンジ
int a4, b4, c4 = 0;//四角形左下の座標計算用 //赤

int sx = 250;//サークルのｘ座標
int sy = 250;//サークルのｙ座標

int menseki = 0;

float h = 20.0f;//円の半径

int gKeyFlg;//キー入力されてるか
int gOldKey;
int gNowKey;

int key;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//入力キー取得
	gOldKey = gNowKey;
	gNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	gKeyFlg = gNowKey & ~gOldKey;



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




		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			x1 -= 8;
			x2 -= 8;
		}

		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) 
		{

			x1 += 8;
			x2 += 8;
		}


		if (CheckHitKey(KEY_INPUT_UP)==1) {
			Y1-=8;
			y2-=8;
		}

		if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
			Y1+=8;
			y2+=8;

		}
		
	
		//動く四角形のDrawBox
		DrawBox(0 + x1, 0+Y1, 40+x2, 40+y2, 0xffff0f, TRUE);

		//真ン中の座標を取ってそっからの距離を倍にできるか
		//boxっぽくできるかどうか
		//xとyの座標むきむき範囲増やせるかどうかだよね
		//別アプローチで円に判定をつけるってのはどうか
		//boxの真ん中の座標から半径を取る
		//真ん中からbox終わりまでのｙ座標x座標とってそこに触ったら、消えるみたいな
		//引くあたい逆にするとか
		
		ip = (40 * (x1-sx)) + (40 * c);
		//cp = (40*)

		//

		a = x1+20-sx;
		b = Y1+20-sy;
		c = sqrt(a * a + b * b);


		DrawCircle(x1+20,Y1+20, 3, 0x008080, TRUE);

		a2 = 40+x2 - sx;
		b2 = 40+y2 - sy;
		c2 = sqrt(a2 * a2 + b2 * b2);

		//x1の４０先、気持ち右上の座標の再現して、そっから求めてる
		a3 = 40+x1 - sx;
		b3 = Y1 - sy;
		c3 = sqrt(a3 * a3 + b3 * b3);

		a4 = x1 - sx;
		b4 = 40+Y1 - sy;
		c4 = sqrt(a4 * a4 + b4 * b4);

		DrawCircle(sx, sy, h, 0xffffff, TRUE);

		m = (x2)*(y2);

		//半径より、cの値が小さくなったら色が変わる
		//半径１００に入って来たら色が変わる
		//円の中心から,半径は１００　ｃ、真ん中の距離から、どこまでなら
		if (c<=h) {
			/*if () {

				DrawFormatString(390, 480, 0xffffff, "hit!!青色 c=%d", c);
			}*/

			DrawCircle(sx, sy, h, 0x008080, TRUE);
		}


		//if (c2 <= h) {
		//	DrawCircle(sx, sy, h, 0x006400, TRUE);
		//}

		//if (c3 <= h) {
		//	DrawCircle(sx, sy, h, 0xffa500, TRUE);
		//}

		//if (c4 <= h) {
		//	DrawCircle(sx, sy, h, 0xdc143c, TRUE);
		//}

		

		DrawFormatString(390, 500, 0xffffff, "青色 c=%f",c);
		DrawFormatString(390, 520, 0xffffff, "緑 c2=%f",c2);
		DrawFormatString(390, 540, 0xffffff, "オレンジ色 c3=%d",c3);
		DrawFormatString(390, 560, 0xffffff, "赤色 c4=%d",c4);
		DrawFormatString(390, 580, 0xffffff, "x1とsxの距離=%f",a);
		DrawFormatString(390, 600, 0xffffff, "y1とsyの距離=%f",b);
	


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

	if (check == 121)check = 0;

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

