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
const int PLAYER_SPEED  = 2;    // 移動速度

/******************************************
 * 構造体の宣言
 ******************************************/
 // プレイヤーの構造体
struct PLAYER
{
	int flg;       // 使用フラグ
	int x, y;      // 座標
	int w, h;      // 幅、高さ
	int speed;     // 移動速度

};

// プレイヤーの変数宣言
struct PLAYER gPlayer;

/******************************************
 * プレイヤー初期化
 ******************************************/
// プレイヤーの初期設定
void PlayerInit(void)
{
	gPlayer.flg = TRUE;         
	gPlayer.x = PLAYER_POS_X;   
	gPlayer.y = PLAYER_POS_Y;   
	gPlayer.w = 50;
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
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0xff0000, TRUE);

			gPlayer.x -= gPlayer.speed + 1;
		}
		// 歩く：左スティックを左に傾ける
		else if (oldkey & PAD_INPUT_LEFT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x -= gPlayer.speed;
		}
		

		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x += gPlayer.speed + 1;
		}
		// 歩く：左スティックを右に傾ける
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0x00ffff, TRUE);
			gPlayer.x += gPlayer.speed;
		}
		
	}
	// プレイヤーの静止
	else
	{
		// プレイヤー仮表示(白)
		DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + 50, SCREEN_HEIGHT, 0xffffff, TRUE);
	}

	// 画面をはみ出さないようにする
	// 右
	if (gPlayer.x > 1000)
	{
		gPlayer.x = 1000;
	}
	// 左
	if (gPlayer.x < 0)
	{
		gPlayer.x = 0;
	}

}

/*************************************
 * プレイヤーの当たり判定
 *************************************/
void HitBoxPlayer(void)
{
	int x1, x2, y1, y2;

	x1 = gPlayer.x;
	y1 = gPlayer.y;
	x2 = gPlayer.x + gPlayer.w;
	y2 = gPlayer.y + gPlayer.h;

	DrawBox(x1, y1, x2, y2, 0x00ff00, TRUE);


	int x3, x4, y3, y4;

	x1 = gPlayer.x;
	y1 = gPlayer.y;
	x2 = gPlayer.x + gPlayer.w;
	y2 = gPlayer.y + gPlayer.h;


}
