#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"
#include "InputControl.h"

int gPlayerImg[5]; // 背景画像
float ax, ay, ar;

float mx0, mx1, my0, my1;

int LFlg = 0;
int RFlg = 0;


/******************************************
 * 変数の宣言
 ******************************************/
//// リンゴの座標
//float ax, ay, ar;
int off, on=0;
int gWalkImg[6];
int gRanImg[6];
int gStopImg;
int Movex = 0;	//動いた位置
int OPx = 0;	//元の位置
int MoveRanx = 0;
int OPxRan = 0;
int Sc[3]={10,35,50};

int Img;	//条件に達するまでの少しの間同じ画像を表示し続ける用
int wImg;		//walkImgの画像どれ表示するかの表示

int RL = 0;	//左か右か判別する変数
int onceFlg = 1;//判別を押されてから一度だけやる為のフラグ
int a;

/******************************************
 * プレイヤー初期化
 ******************************************/

Player::Player()
{
	gPlayer.flg = TRUE;         
	gPlayer.x = PLAYER_POS_X;   
	gPlayer.y = PLAYER_POS_Y;   
	gPlayer.w = 76+30;
	gPlayer.h = 150;
	gPlayer.speed = PLAYER_SPEED;
}

Player::~Player()
{

}


int Player::LoadPlayerImg(void)
{
	//// プレイヤー(右向きに走る)画像の読込
	//if ((gPlayerImg[0] = LoadGraph("images/プレイヤー１.png")) == -1) return -1;
	//// プレイヤー(左向きに走る)画像の読込
	//if ((gPlayerImg[1] = LoadGraph("images/RunL.png")) == -1) return -1;
	//// プレイヤー(右向きに歩く)画像の読込
	//if ((gPlayerImg[2] = LoadGraph("images/プレイヤー２.png")) == -1) return -1;
	//// プレイヤー(左向きに歩く)画像の読込
	//if ((gPlayerImg[3] = LoadGraph("images/WalkL.png")) == -1) return -1;
	//// プレイヤー(静止)画像の読込
	//if ((gPlayerImg[4] = LoadGraph("images/プレイヤー３.png")) == -1) return -1;

	//画像分割読み込み
/*以下LoadDivGraphの引数の内容
*ファイル名
*画像の数
*横方向の画像の数
*縦方向の画像の数
*画像一つの横サイズ
*画像一つの縦サイズ
*画像を格納する配列
*/
	if (LoadDivGraph("images/BearWalk.png", 4, 2, 2, 32, 32, gWalkImg) == -1)return -1;
	if (LoadDivGraph("images/BearRan.png", 6, 3, 2, 32, 32, gRanImg) == -1)return -1;
	if ((gStopImg = LoadGraph("images/kuma.png")) == -1) return -1;
	return 0;

}

/*************************************
 * プレイヤーの移動
 *************************************/
void Player::PlayerControl(XINPUT_STATE input, int gamemode,int Pause_flg)
{

	// プレイヤーの左右移動
	if (input & PAD_INPUT_LEFT || input & PAD_INPUT_RIGHT)
	{
		// 左移動
		// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
		if (input & PAD_INPUT_LEFT && input & PAD_INPUT_1)
		{
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed + 2;
		}
		// 歩く：左スティックを左に傾ける
		else if (input & PAD_INPUT_LEFT)
		{
			// プレイヤー仮表示(水色)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
			gPlayer.x -= gPlayer.speed;
		}
		if (Pause_flg == 0) {
			// プレイヤーの左右移動
			if (InputControl::GetKey(PAD_INPUT_LEFT) || InputControl::GetKey(PAD_INPUT_RIGHT))
			{
				// 左移動
				// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
				if (InputControl::GetKey(PAD_INPUT_LEFT) && InputControl::GetKey(PAD_INPUT_1))
				{
					RL = 0;
					PlayerRan(RL);
					gPlayer.x -= gPlayer.speed + 2;
					MoveRanx = gPlayer.x;
				}

				// 歩く：左スティックを左に傾ける
				else if (InputControl::GetKey(PAD_INPUT_LEFT))
				{

					RL = 0;
					PlayerWalk(RL);
					gPlayer.x -= gPlayer.speed;
					Movex = gPlayer.x;

				}

				// 右移動
				// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
				if (input & PAD_INPUT_RIGHT && input & PAD_INPUT_1)
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

				// 右移動
				// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
				if (InputControl::GetKey(PAD_INPUT_RIGHT) && InputControl::GetKey(PAD_INPUT_1))
				{
					RL = 3;
					PlayerRan(RL);

					gPlayer.x += gPlayer.speed + 2;
					MoveRanx = gPlayer.x;

				}
				// 歩く：左スティックを右に傾ける
				else if (InputControl::GetKey(PAD_INPUT_RIGHT))
				{


					RL = 2;

					PlayerWalk(RL);
					gPlayer.x += gPlayer.speed;
					Movex = gPlayer.x;

				}

			}
			// プレイヤーの静止
			else
			{
				// プレイヤー仮表示(白)
				//DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xffffff, TRUE);

				//プレイヤー止まってる画像表示
				DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gStopImg, TRUE);
			}
		}
		else
		{
			//Pauseの時の画像
			DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gStopImg, TRUE);
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
}


//画像を点滅できるようにする
int Player:: PlayerFlashing(int& Count, int& on, int& off) {

	if (Count <= 120) {

		//120秒たつまで、20f感覚で点滅
		if (on == 20) {
			off = 0;

			DrawBox(0, 0, 40, 40, 0x000000, TRUE);
			// プレイヤー仮表示(赤)
			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);

			return off;

		}

		if (off == 20) {
			on = 0;
			DrawBox(0, 0, 40, 40, 0xff0000, FALSE);

			DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x000000, TRUE);


			return on;
		}

	}
	
}

//Playerの歩く動き
void Player::PlayerWalk(int wImg) {

	if (abs(Movex - OPx) > 50) {
		//一瞬画像が表示されなくなる時間ができるので表示
		DrawExtendGraph(gPlayer.x - 7, gPlayer.y - 10, gPlayer.x + gPlayer.w + 7, SCREEN_HEIGHT, gWalkImg[Img], TRUE);
		//OPxが動かなくならないように
		OPx = Movex-10;
	}
	else {
	//歩く動き
	switch (abs(Movex - OPx)) {
	case 20:
		DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gWalkImg[wImg], TRUE);
		Img = wImg;
		break;
	case 50:
		DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gWalkImg[wImg + 1], TRUE);
		Img = wImg + 1;
		OPx = gPlayer.x;
		break;
	default:
		DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gWalkImg[Img], TRUE);

	}

}

	
}

//Playerの走る動き
void Player::PlayerRan(int rImg)
{
	if (abs(MoveRanx - OPxRan) > 56) {
		/*OPxが動かなくならないように
		歩く動きからZで切り替えたとき、caseで判定できる数より、
		MoveRanx-OPxRanが大きい場合、画像が動かなくなってしまうので
		if文でリセットしている*/
		OPxRan = MoveRanx;
	}
		//走る動き
		switch (abs(MoveRanx - OPxRan)) {
		case 21:
			DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gRanImg[rImg], TRUE);
			Img = rImg;
			break;
		case 35:
			DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gRanImg[rImg + 1], TRUE);
			Img = rImg + 1;
			break;
		case 56:
			DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gRanImg[rImg + 2], TRUE);
			Img = rImg + 2;
			OPxRan = gPlayer.x;
			break;
		default:
			DrawExtendGraph(gPlayer.x-7, gPlayer.y-10, gPlayer.x + gPlayer.w+7, SCREEN_HEIGHT, gRanImg[Img], TRUE);
		}

		//DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg+1], TRUE);
}
