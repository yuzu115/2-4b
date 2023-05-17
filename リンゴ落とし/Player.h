#pragma once
class Player
{
private:

	// 画面サイズ
	const int SCREEN_WIDTH = 1280;   // 幅
	const int SCREEN_HEIGHT = 720;    // 高さ

	 // プレイヤーの初期値の定数
	const int PLAYER_POS_X = 600;  // X座標 
	const int PLAYER_POS_Y = 527;  // Y座標 
	const int PLAYER_SPEED = 5;    // 移動速度

public:
	// プレイヤーの構造体
	typedef struct 
	{
		int flg;       // 使用フラグ
		float x, y;      // 座標
		int w, h;      // 幅、高さ
		int speed;     // 移動速度

	}PLAYER;

	// プレイヤーの変数宣言
	PLAYER gPlayer;

	// リンゴの座標
	float ax, ay, ar;

	int LFlg = 0;
	int RFlg = 0;

	int gPlayerImg[5]; // 背景画像


	void PlayerInit(void);                            // プレイヤー初期化
	void PlayerControl(int oldkey, int gamemode);     // プレイヤー制御
	void GetApple(float ax0, float ay0, float ar0);         // リンゴの座標を変数に格納
	void HitPlayer(void);                            // リンゴとプレイヤーの当たり判定
	float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
	int LoadPlayerImg(void);       // 画像読込
};