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
	typedef struct
	{
		int flg;       // 使用フラグ
		float x, y;      // 座標
		float w, h;      // 幅、高さ
		float speed;     // 移動速度
	}PLAYER;

	PLAYER gPlayer;

public:

/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
	Player();
	~Player();                  
	void PlayerControl(XINPUT_STATE input, int gamemode,int Pause_flg);     // プレイヤー制御
	void GetApple(Apple::APPLE_DATA* a);
	int HitPlayer(void);                          // リンゴとプレイヤーの当たり判定
	float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
	int LoadPlayerImg(void);       // 画像読込

	void PlayerXControl(XINPUT_STATE input, int& button_flg);     // プレイヤー制御（XInput）
	int PlayerFlashing(int& Count, int& on, int& off);	//プレイヤー点滅処理
	void PlayerWalk(int wImg);		//歩く画像切り替え処理
	void PlayerRan(int rImg);		//走る画像切り替え処理
};

