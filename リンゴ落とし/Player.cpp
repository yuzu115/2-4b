#include"DxLib.h"
#include <math.h>
#include"Player.h"


/******************************************
 * 定数の宣言
 ******************************************/
 // プレイヤーの初期値の定数
const int PLAYER_POS_X  = 640;  // X座標 
const int PLAYER_POS_Y  = 600;  // Y座標 
const int PLAYER_WIDTH  = 1000; // 幅
const int PLAYER_HEIGHT = 0;    // 高さ
const int PLAYER_SPEED  = 2;    // 移動速度

/******************************************
 * 構造体の宣言
 ******************************************/
 // プレイヤーの構造体
struct PLAYER
{
	int flg;       // 使用フラグ
	int x, y;      // 座標
	int w, h;      // 高さ
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
	gPlayer.w = PLAYER_WIDTH;   
	gPlayer.h = PLAYER_HEIGHT;
	gPlayer.speed = PLAYER_SPEED;
}

/*************************************
 * プレイヤーの移動
 *************************************/
void PlayerControl(int oldkey,int gamemode)
{
	// プレイヤー仮表示
	DrawCircle(gPlayer.x, PLAYER_POS_Y, 50, 0xffffff, TRUE);

	// 左右移動
	if (gPlayer.flg == TRUE)
	{
		// 左移動
		// ダッシュ：Aボタンを押したまま左スティック操作する
		if (oldkey & PAD_INPUT_LEFT && oldkey & PAD_INPUT_1)
		{
			DrawCircle(gPlayer.x, PLAYER_POS_Y, 50, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed * 2;
		}
		// 歩く：左スティック操作のみ
		else if (oldkey & PAD_INPUT_LEFT)
		{
			gPlayer.x -= gPlayer.speed;
		}
		

		// 右移動
		// ダッシュ：Aボタンを押したまま左スティック操作する
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			DrawCircle(gPlayer.x, PLAYER_POS_Y, 50, 0xff0000, TRUE);
			gPlayer.x += gPlayer.speed * 2;
		}
		// 歩く：左スティック操作のみ
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			gPlayer.x += gPlayer.speed;
		}
		
	}

	// 画面をはみ出さないようにする
	// 右
	if (gPlayer.x > PLAYER_WIDTH)
	{
		gPlayer.x = PLAYER_WIDTH;
	}
	// 左
	if (gPlayer.x < 50)
	{
		gPlayer.x = 50;
	}

}
/*************************************
 * プレイヤーの当たり判定
 *************************************/
void HitBoxPlayer(PLAYER* p)
{
	// x,yは中心座標とする
	// px1,py1 左上 px2,py1 右下
	int px1 = (p->x - (p->w / 2)) + 5;
	int py1 = (p->y - (p->h / 2)) + 5;
	int px2 = (px1 + p->w) - 10;
	int py2 = (py1 + p->h) - 5;

	// 矩形当たり判定範囲表示(確認用)
	DrawBox(px1, py1, px2, py2, 0xff0000, TRUE);

}
