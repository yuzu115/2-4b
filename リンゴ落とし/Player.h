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
void PlayerInit(void);                            // プレイヤー初期化
void PlayerControl(int gamemode,int& Pause_flg);     // プレイヤー制御
void GetApple(float ax0, float ay0, float ar0);         // リンゴの座標を変数に格納
void HitPlayer(void);                            // リンゴとプレイヤーの当たり判定
float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
int PlayerFlashing(int& Count,int& on,int& off);
void PlayerWalk(int wImg);
void PlayerRan(int rImg);
int LoadImg(void);

	Player();
	~Player();                  
	void PlayerControl(int oldkey, int gamemode);     // プレイヤー制御
	void GetApple(Apple::APPLE_DATA* a);
	int HitPlayer(void);                          // リンゴとプレイヤーの当たり判定
	float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
	int LoadPlayerImg(void);       // 画像読込
};

