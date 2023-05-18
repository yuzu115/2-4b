#pragma once
#include"DrawApple.h"
// 画面サイズ
#define SCREEN_WIDTH  1280   // 幅
#define SCREEN_HEIGHT 720    // 高さ

 // プレイヤーの初期値の定数
#define PLAYER_POS_X  600  // X座標 
#define PLAYER_POS_Y  527  // Y座標 
#define PLAYER_SPEED  5    // 移動速度

class Player
{
private:
	// リンゴの座標
	static float ax, ay, ar;

	static float mx0, mx1, my0, my1;

	int LFlg = 0;
	int RFlg = 0;

	int gPlayerImg[5]; // 背景画像

public:

	typedef struct
	{
		int flg;       // 使用フラグ
		float x, y;      // 座標
		float w, h;      // 幅、高さ
		float speed;     // 移動速度
	}PLAYER;

	struct PLAYER gPlayer;


	void PlayerInit(void);                            // プレイヤー初期化
	void PlayerControl(int oldkey, int gamemode);     // プレイヤー制御
	//void GetApple(float ax0, float ay0, float ar0);         // リンゴの座標を変数に格納

	int HitPlayer(APPLE_DATE* a);                          // リンゴとプレイヤーの当たり判定
	float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
	int LoadPlayerImg(void);       // 画像読込
};

// 二乗+二乗の計算
float Player::Pythagorean(float px, float py, float ax, float ay)
{
	float dx, dy, r;

	dx = px - ax;
	dy = py - ay;

	r = (dx * dx) + (dy * dy);

	return (r);

}