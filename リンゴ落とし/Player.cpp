#include"DxLib.h"
#include <math.h>
#include"Player.h"

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

}

/*************************************
 * プレイヤーの移動
 *************************************/
void PlayerControl(int oldkey,int gamemode)
{

	// プレイヤーの左右移動
	if (oldkey & PAD_INPUT_LEFT || oldkey & PAD_INPUT_RIGHT)
	{

		// 左移動
		// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed + 2;
		}
		// 歩く：左スティックを左に傾ける
		else if (oldkey & PAD_INPUT_LEFT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x -= gPlayer.speed;
		}


		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x += gPlayer.speed + 2;
		}
		// 歩く：左スティックを右に傾ける
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x += gPlayer.speed;
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
	DrawBox(mx0, my0, mx1, my1, 0x000000, TRUE);
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

void PlayerFlashing() {

}