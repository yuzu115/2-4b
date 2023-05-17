#pragma once
class Player
{
private:
		int flg;       // 使用フラグ
		float x, y;      // 座標
		float w, h;      // 幅、高さ
		float speed;     // 移動速度

	// リンゴの座標
	static float ax, ay, ar;

	static float mx0, mx1, my0, my1;

	int LFlg = 0;
	int RFlg = 0;

	int gPlayerImg[5]; // 背景画像

public:

	void PlayerInit(void);                            // プレイヤー初期化
	void PlayerControl(int oldkey, int gamemode);     // プレイヤー制御
	//void GetApple(float ax0, float ay0, float ar0);         // リンゴの座標を変数に格納
	int HitPlayer(Apple::APPLE_DATE* a);                          // リンゴとプレイヤーの当たり判定
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