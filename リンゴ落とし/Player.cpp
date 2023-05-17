#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"

// 画面サイズ
#define SCREEN_WIDTH  1280   // 幅
#define SCREEN_HEIGHT 720    // 高さ

 // プレイヤーの初期値の定数
#define PLAYER_POS_X  600  // X座標 
#define PLAYER_POS_Y  527  // Y座標 
#define PLAYER_SPEED  5    // 移動速度

float Player::ax, ay, ar;

float Player::mx0, mx1, my0, my1;

Player pl;
Apple ap;
/******************************************
 * 定数の宣言
 ******************************************/
//// 画面サイズ
//const int SCREEN_WIDTH  = 1280;   // 幅
//const int SCREEN_HEIGHT = 720;    // 高さ
//
// // プレイヤーの初期値の定数
//const int PLAYER_POS_X  = 600;  // X座標 
//const int PLAYER_POS_Y  = 527;  // Y座標 
//const int PLAYER_SPEED  = 5;    // 移動速度

/******************************************
 * 構造体の宣言
 ******************************************/
// // プレイヤーの構造体
//struct PLAYER
//{
//	int flg;       // 使用フラグ
//	float x, y;      // 座標
//	int w, h;      // 幅、高さ
//	int speed;     // 移動速度
//
//};
//
//// プレイヤーの変数宣言
//struct PLAYER gPlayer;

/******************************************
 * 変数の宣言
 ******************************************/
//// リンゴの座標
//float ax, ay, ar;
//
//int LFlg = 0;
//int RFlg = 0;
//
//int gPlayerImg[5]; // 背景画像

/******************************************
 * プレイヤー初期化
 ******************************************/
// プレイヤーの初期設定
void Player::PlayerInit(void)
{
	flg = TRUE;         
	x = PLAYER_POS_X;   
	y = PLAYER_POS_Y;   
	w = 80;
	h = 150;
	speed = PLAYER_SPEED;

}

int Player::LoadPlayerImg(void)
{
	// プレイヤー(右向きに走る)画像の読込
	if ((gPlayerImg[0] = LoadGraph("images/プレイヤー１.png")) == -1) return -1;
	// プレイヤー(左向きに走る)画像の読込
	if ((gPlayerImg[1] = LoadGraph("images/RunL.png")) == -1) return -1;
	// プレイヤー(右向きに歩く)画像の読込
	if ((gPlayerImg[2] = LoadGraph("images/プレイヤー２.png")) == -1) return -1;
	// プレイヤー(左向きに歩く)画像の読込
	if ((gPlayerImg[3] = LoadGraph("images/WalkL.png")) == -1) return -1;
	// プレイヤー(静止)画像の読込
	if ((gPlayerImg[4] = LoadGraph("images/プレイヤー３.png")) == -1) return -1;

	return 0;
}

/*************************************
 * プレイヤーの移動
 *************************************/
void Player::PlayerControl(int oldkey,int gamemode)
{
	Apple app;
	LoadPlayerImg();

	// プレイヤーの左右移動
	if (oldkey & PAD_INPUT_LEFT || oldkey & PAD_INPUT_RIGHT)
	{

		// 左移動
		// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(x, y, x + w, SCREEN_HEIGHT, 0xff0000, TRUE);
		    x -= speed + 2;
		}
		// 歩く：左スティックを左に傾ける
		else if (oldkey & PAD_INPUT_LEFT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(x, y, x + w, SCREEN_HEIGHT, 0xff0000, TRUE);
			x -= speed;
		}

		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(x, y, x + w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			x += speed + 2;
			
		}
		// 歩く：左スティックを右に傾ける
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(x, y, x + w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			x += speed;
			
		}

	}
	// プレイヤーの静止
	else
	{
	// プレイヤー仮表示(白)
		DrawBox(x, y, x + w, SCREEN_HEIGHT, 0xffffff, TRUE);
	}

	// 画面をはみ出さないようにする
	// 右
	if (x > 950)
	{
		x = 950;
	}
	// 左
	if (x < -20)
	{
		x = -20;
	}

	// プレイヤーとリンゴの当たり判定 
	//HitPlayer(,&gPlayer);

}

//// リンゴの座標を変数sx,sy,srに格納
//void Player::GetApple(float ax0, float ay0, float ar0)
//{
//	// リンゴの座標
//
//	ax = ax0;
//	ay = ay0;
//	ar = ar0;
//
//	//DrawCircle(sx, sy, sr, 0x000000, TRUE);
//
//}

//// 二乗+二乗の計算
//float Player::Pythagorean(float px, float py, float ax, float ay)
//{
//	float dx, dy, r;
//
//	dx = px - ax;
//	dy = py - ay;
//
//	r = (dx * dx) + (dy * dy);
//
//	return (r);
//
//}

// リンゴとプレイヤーの当たり判定
int Player::HitPlayer(Apple::APPLE_DATE* a)
{
	// リンゴとプレイヤーが当たっているか判定
	int flg = 0;

	mx0 = x;
	mx1 = mx0 + w;
	my0 = y;
	my1 = SCREEN_HEIGHT;

	ax = a->x;
	ay = a->y;
	ar = a->r;



	// プレイヤーの当たり判定表示
	//DrawBox(mx0, my0, mx1, my1, 0x000000, TRUE);
	// リンゴの当たり判定表示
	//DrawCircle(ax, ay, ar, 0x000000, TRUE);

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
	if (pl.Pythagorean(mx0, my0, ax, ay) < ar * ar || pl.Pythagorean(mx1, my0, ax, ay) < ar *ar ||
		pl.Pythagorean(mx0, my1, ax, ay) < ar * ar || pl.Pythagorean(mx1, my1, ax, ay) < ar * ar)
	{
		flg = 3;
	}

    // 上の1〜３のどれか一つが当てはまったら当たっている
	if (flg == 1 || flg == 2 || flg == 3)
	{
		// 当たっていたらリンゴの色を白に
		DrawCircle(ax, ay, ar, 0xffffff, TRUE);
		return TRUE;
	}
}