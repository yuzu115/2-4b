#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"


int gPlayerImg[5]; // 背景画像
float ax, ay, ar;

float mx0, mx1, my0, my1;

int LFlg = 0;
int RFlg = 0;


/******************************************
 * プレイヤー初期化
 ******************************************/

Player::Player()
{
	gPlayer.flg = TRUE;
	gPlayer.x = PLAYER_POS_X;
	gPlayer.y = PLAYER_POS_Y;
	gPlayer.w = 80;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;
}

Player::~Player()
{

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
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed;
		}

		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (oldkey & PAD_INPUT_RIGHT && oldkey & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			gPlayer.x += gPlayer.speed + 2;
			
		}
		// 歩く：左スティックを右に傾ける
		else if (oldkey & PAD_INPUT_RIGHT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
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
	if (gPlayer.x < -20)
	{
		gPlayer.x = -20;
	}

	mx0 = gPlayer.x;
	mx1 = mx0 + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	HitPlayer();
}


// 二乗+二乗の計算
float Player::Pythagorean(float px, float py, float ax, float ay)
{
	float dx, dy, r;

	dx = px - ax;
	dy = py - ay;

	r = (dx * dx) + (dy * dy);

	return (r);

}

void Player::GetApple(Apple::APPLE_DATA* a)
{
	ax = a->x;
	ay = a->y;
	ar = a->r;
}

// リンゴとプレイヤーの当たり判定
int Player::HitPlayer(void)
{
	// リンゴとプレイヤーが当たっているか判定
	int flg = 0;

	//DrawBox(mx0, my0, mx1,my1, 0x000000, TRUE);
	//DrawCircle(ax, ay, ar, 0xffffff, TRUE);

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
		DrawString(0, 150, "HIt", 0xffffff);
		flg = 4;
		return TRUE;
	}
	return FALSE;
}

/*************************************
 * プレイヤーの移動(XInput)
 *************************************/
void Player::PlayerXControl(XINPUT_STATE input, int& button_flg)
{

	// プレイヤーの左右移動
	if (input.ThumbLX < 128 || input.ThumbLX > 128)
	{
		// 左移動
		// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
		if (input.ThumbLX < 128 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed + 2;
		}
		// 歩く：左スティックを左に傾ける
		else if (input.ThumbLX < 128)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed;
		}

		// 右移動
		// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
		if (input.ThumbLX > 128 && input.Buttons[XINPUT_BUTTON_A] == 1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
			gPlayer.x += gPlayer.speed + 2;

		}
		// 歩く：左スティックを右に傾ける
		else if (input.ThumbLX > 128)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x00ff00, TRUE);
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
	if (gPlayer.x < -20)
	{
		gPlayer.x = -20;
	}

	mx0 = gPlayer.x;
	mx1 = mx0 + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	HitPlayer();
}
