#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"InputControl.h"


/******************************************
 * 定数の宣言
 ******************************************/
// 画面サイズ
const int SCREEN_WIDTH  = 1280;   // 幅
const int SCREEN_HEIGHT = 720;    // 高さ

 // プレイヤーの初期値の定数
const int PLAYER_POS_X  = 600;  // X座標 
const int PLAYER_POS_Y  = 570;  // Y座標 
const int PLAYER_SPEED  = 5;    // 移動速度

/******************************************
 * 構造体の宣言
 ******************************************/
 // プレイヤーの構造体
struct PLAYER
{
	int flg;       // 使用フラグ
	float x, y;      // 座標
	int w, h;      // 幅、高さ
	int speed;     // 移動速度

};

// プレイヤーの変数宣言
struct PLAYER gPlayer;

/******************************************
 * 変数の宣言
 ******************************************/
// リンゴの座標
float ax, ay, ar;
//int off, on=0;
//int gPlayerImg[];
int gWalkImg[6];
int gRanImg[6];
int Movex = 0;	//動いた位置
int OPx = 0;	//元の位置
int MoveRanx = 0;
int OPxRan = 0;
//int Sc[3]={10,35,50};

int Img;	//条件に達するまでの少しの間同じ画像を表示し続ける用
int wImg;		//walkImgの画像どれ表示するかの表示

int RL = 0;	//左か右か判別する変数
int onceFlg = 1;//判別を押されてから一度だけやる為のフラグ
int a;

/******************************************
 * プレイヤー初期化
 ******************************************/
// プレイヤーの初期設定
void PlayerInit(void)
{
	gPlayer.flg = TRUE;         
	gPlayer.x = PLAYER_POS_X;   
	gPlayer.y = PLAYER_POS_Y;   
	gPlayer.w = 76;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;


	OPx = gPlayer.x;
	OPxRan = gPlayer.x;

}

/*************************************
 * プレイヤーの移動
 *************************************/
void PlayerControl(int gamemode)
{
	LoadImg();

	// プレイヤーの左右移動
	if (InputControl::GetKey(PAD_INPUT_LEFT) || InputControl::GetKey(PAD_INPUT_RIGHT))
	{
		// 左移動
		// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
		if (InputControl::GetKey(PAD_INPUT_LEFT) && InputControl::GetKey(PAD_INPUT_1))
		{
			RL = 0;
			PlayerRan(RL);

			gPlayer.x -= gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}

		// 歩く：左スティックを左に傾ける
		else if (InputControl::GetKey(PAD_INPUT_LEFT))
		{

			RL = 0;
			PlayerWalk(RL);
			gPlayer.x -= gPlayer.speed;
			Movex = gPlayer.x;
			
		}


		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (InputControl::GetKey(PAD_INPUT_RIGHT) && InputControl::GetKey(PAD_INPUT_1))
		{
			RL = 3;
			PlayerRan(RL);

			gPlayer.x += gPlayer.speed + 2;
			MoveRanx = gPlayer.x;

		}
		// 歩く：左スティックを右に傾ける
		else if (InputControl::GetKey(PAD_INPUT_RIGHT))
		{
			

			RL = 3;

			PlayerWalk(RL);
			gPlayer.x += gPlayer.speed;
			Movex = gPlayer.x;
			
		}

	}
	// プレイヤーの静止
	else
	{
	// プレイヤー仮表示(白)
	DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);
	}

	// 画面をはみ出さないようにする
	// 右
	if (gPlayer.x > 950)
	{
		gPlayer.x = 950;
	}
	// 左
	if (gPlayer.x < 0)
	{
		gPlayer.x = 0;
	}

	// プレイヤーとリンゴの当たり判定 
	HitPlayer();


	DrawFormatString(390, 30, 0x000000, "Movex=%d",Movex);
	DrawFormatString(390, 50, 0x000000, "OPx=%d",OPx);
	DrawFormatString(390, 70, 0x000000, "Movex-OPx=%d",abs(Movex-OPx));	
	DrawFormatString(390, 90, 0x000000, "onceFlg=%d",onceFlg);
	DrawFormatString(390, 110, 0x000000, "RL=%d",RL);

	DrawFormatString(390, 130, 0x000000, "MoveRanx=%d", MoveRanx);
	DrawFormatString(390, 150, 0x000000, "OPxRan=%d", OPxRan);
	DrawFormatString(390, 170, 0x000000, "MoveRanx-OPxRan=%d", abs(MoveRanx - OPxRan));
	//DrawFormatString(390, 190, 0x000000, "Move-12-OPRan=%d", abs(MoveRanx-12 - OPxRan));
}

// リンゴの座標を変数sx,sy,srに格納
void GetApple(float ax0, float ay0, float ar0)
{
	// リンゴの座標

	ax = ax0;
	ay = ay0;
	ar = ar0;

	//DrawCircle(sx, sy, sr, 0x000000, TRUE);

}

// 二乗+二乗の計算
float Pythagorean(float px, float py, float ax, float ay)
{
	float dx, dy, r;

	dx = px - ax;
	dy = py - ay;

	r = (dx * dx) + (dy * dy);

	return (r);

}

// リンゴとプレイヤーの当たり判定
void HitPlayer(void)
{
	// リンゴとプレイヤーが当たっているか判定
	int flg = 0;
	float mx0, mx1, my0, my1;

	mx0 = gPlayer.x;
	mx1 = gPlayer.x + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	// プレイヤーの当たり判定表示
	//DrawBox(mx0, my0, mx1, my1, 0x000000, TRUE);
	// リンゴの当たり判定表示
	DrawCircle(ax, ay, ar, 0x000000, TRUE);

	// 1:円の中心が長方形から見て上・中・下の位置にある場合
	if ((mx0 < ax && ax < mx1) && (my0 - ar < ay && ay < my1 + ar))
	{
		flg = 1;
	}
	// 2:円の中心が長方形から見て左・中・右の位置にある場合
	if ((mx0 - ar < ax && ax < mx1 + ar) && (my0 < ay && ay < my1))
	{
		flg = 2;
	}
	// 3:円の中心が長方形から見て斜め上下の位置にある場合
	if (Pythagorean(mx0, my0, ax, ay) < ar * ar || Pythagorean(mx1, my0, ax, ay) < ar *ar ||
		Pythagorean(mx0, my1, ax, ay) < ar * ar || Pythagorean(mx1, my1, ax, ay) < ar * ar)
	{
		flg = 3;
	}

    // 上の1～３のどれか一つが当てはまったら当たっている
	if (flg == 1 || flg == 2 || flg == 3)
	{
		// 当たっていたらリンゴの色を白に
		DrawCircle(ax, ay, ar, 0xffffff, TRUE);
	}
}


//画像を点滅できるようにする
int PlayerFlashing(int& Count,int& on,int& off) {

	if (Count <= 120) {

		//120秒たつまで、20f感覚で点滅
		if (on == 20) {
			off = 0;

			DrawBox(0, 0, 40, 40, 0x000000, TRUE);
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);

			return off;

		}

		if (off == 20) {
			on = 0;
			DrawBox(0, 0, 40, 40, 0xff0000, FALSE);

			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x000000, TRUE);


			return on;
		}

	}
	
}

//Playerの歩く動き
void PlayerWalk(int wImg) {

	if (abs(Movex - OPx) > 50) {
		//OPxが動かなくならないように
		OPx = Movex-10;
	}
	else {

	//歩く動き
	switch (abs(Movex - OPx)) {
	case 10:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg], TRUE);
		Img = wImg;
		break;
	case 35:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg + 1], TRUE);
		Img = wImg + 1;
		break;
	case 50:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg + 2], TRUE);
		Img = wImg + 2;
		OPx = gPlayer.x;
		break;
	default:
		DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[Img], TRUE);

	}

}

	
}

//Playerの走る動き
void PlayerRan(int rImg)
{
	if (abs(MoveRanx - OPxRan) > 56) {
		/*OPxが動かなくならないように
		歩く動きからZで切り替えたとき、caseで判定できる数より、
		MoveRanx-OPxRanが大きい場合、画像が動かなくなってしまうので
		if文でリセットしている*/
		OPxRan = MoveRanx;
	}
		//走る動き
		switch (abs(MoveRanx - OPxRan)) {
		case 21:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg], TRUE);
			Img = rImg;
			break;
		case 35:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 1], TRUE);
			Img = rImg + 1;
			break;
		case 56:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 2], TRUE);
			Img = rImg + 2;
			OPxRan = gPlayer.x;
			break;
		default:
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[Img], TRUE);
		}

		//DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg+1], TRUE);
}

int LoadImg(void) {
	//画像分割読み込み
	/*以下LoadDivGraphの引数の内容
	*ファイル名
	*画像の数
	*横方向の画像の数
	*縦方向の画像の数
	*画像一つの横サイズ
	*画像一つの縦サイズ
	*画像を格納する配列
	*/
	if (LoadDivGraph("images/PLwalk2.png", 6, 3, 2, 32, 32, gWalkImg) == -1)return -1;
	if (LoadDivGraph("images/PLRan.png", 6, 3, 2, 32, 32, gRanImg) == -1)return -1;
	return 0;
}

/*************************************
 * プレイヤーの移動（XInput）
 *************************************/
void PlayerXControl(XINPUT_STATE input, int& Button_flg)
{
	LoadImg();

	// プレイヤーの左右移動（左スティック）
	if (input.ThumbLX < 128 || input.ThumbLX > 128)
	{
		// 左移動
		// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
		if (input.ThumbLX < 128 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			RL = 0;
			PlayerRan(RL);

			gPlayer.x -= gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}

		// 歩く：左スティックを左に傾ける
		else if (input.ThumbLX < 128)
		{
			RL = 0;
			PlayerWalk(RL);
			gPlayer.x -= gPlayer.speed;
			Movex = gPlayer.x;
		}

		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (input.ThumbLX > 128 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			RL = 3;
			PlayerRan(RL);

			gPlayer.x += gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}
		// 歩く：左スティックを右に傾ける
		else if (input.ThumbLX > 128)
		{
			RL = 3;

			PlayerWalk(RL);
			gPlayer.x += gPlayer.speed;
			Movex = gPlayer.x;
		}

	}
	// プレイヤーの静止
	else
	{
		// プレイヤー仮表示(白)
		DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);
	}

	// 画面をはみ出さないようにする
	// 右
	if (gPlayer.x > 950)
	{
		gPlayer.x = 950;
	}
	// 左
	if (gPlayer.x < 0)
	{
		gPlayer.x = 0;
	}

	// プレイヤーとリンゴの当たり判定 
	HitPlayer();


	DrawFormatString(390, 30, 0x000000, "Movex=%d", Movex);
	DrawFormatString(390, 50, 0x000000, "OPx=%d", OPx);
	DrawFormatString(390, 70, 0x000000, "Movex-OPx=%d", abs(Movex - OPx));
	DrawFormatString(390, 90, 0x000000, "onceFlg=%d", onceFlg);
	DrawFormatString(390, 110, 0x000000, "RL=%d", RL);

	DrawFormatString(390, 130, 0x000000, "MoveRanx=%d", MoveRanx);
	DrawFormatString(390, 150, 0x000000, "OPxRan=%d", OPxRan);
	DrawFormatString(390, 170, 0x000000, "MoveRanx-OPxRan=%d", abs(MoveRanx - OPxRan));
	//DrawFormatString(390, 190, 0x000000, "Move-12-OPRan=%d", abs(MoveRanx-12 - OPxRan));
}

/*************************************
 * プレイヤーの移動（XInputStick）
 *************************************/
void PlayerXIControl(XINPUT_STATE input)
{
	LoadImg();

	// プレイヤーの左右移動（左スティック）
	if (input.ThumbLX < 128 || input.ThumbLX > 128)
	{
		// 左移動
		// ダッシュ：左スティックを左に傾ける
		if (input.ThumbLX < -150000)
		{
			RL = 0;
			PlayerRan(RL);

			gPlayer.x -= gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}

		// 歩く：左スティックを左に傾ける
		else if (input.ThumbLX < 128)
		{
			RL = 0;
			PlayerWalk(RL);
			gPlayer.x -= gPlayer.speed;
			Movex = gPlayer.x;
		}

		// 右移動
		// ダッシュ：左スティックを右に傾ける
		if (input.ThumbLX > 15000)
		{
			RL = 3;
			PlayerRan(RL);

			gPlayer.x += gPlayer.speed + 2;
			MoveRanx = gPlayer.x;
		}
		// 歩く：左スティックを右に傾ける
		else if (input.ThumbLX > 128)
		{
			RL = 3;

			PlayerWalk(RL);
			gPlayer.x += gPlayer.speed;
			Movex = gPlayer.x;
		}

	}
	// プレイヤーの静止
	else
	{
		// プレイヤー仮表示(白)
		DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);
	}

	// 画面をはみ出さないようにする
	// 右
	if (gPlayer.x > 950)
	{
		gPlayer.x = 950;
	}
	// 左
	if (gPlayer.x < 0)
	{
		gPlayer.x = 0;
	}

	// プレイヤーとリンゴの当たり判定 
	HitPlayer();


	DrawFormatString(390, 30, 0x000000, "Movex=%d", Movex);
	DrawFormatString(390, 50, 0x000000, "OPx=%d", OPx);
	DrawFormatString(390, 70, 0x000000, "Movex-OPx=%d", abs(Movex - OPx));
	DrawFormatString(390, 90, 0x000000, "onceFlg=%d", onceFlg);
	DrawFormatString(390, 110, 0x000000, "RL=%d", RL);

	DrawFormatString(390, 130, 0x000000, "MoveRanx=%d", MoveRanx);
	DrawFormatString(390, 150, 0x000000, "OPxRan=%d", OPxRan);
	DrawFormatString(390, 170, 0x000000, "MoveRanx-OPxRan=%d", abs(MoveRanx - OPxRan));
	//DrawFormatString(390, 190, 0x000000, "Move-12-OPRan=%d", abs(MoveRanx-12 - OPxRan));
}
