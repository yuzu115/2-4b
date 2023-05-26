#include"DxLib.h"
#include <math.h>
#include"Player.h"
#include"DrawApple.h"


float ax=0, ay=0, ar=0;

float mx0=0, mx1=0, my0=0, my1=0;

Apple app;
Player p;

int on = 20;	//20fカウント用
int off = 20;	//20fカウント用
int FlashCount=0;//プレイヤー画像点滅用
int Poflg=0;

int InitFlg=0;	//初期化フラグ

int LFlg = 0;
int RFlg = 0;

int gStopImg=0;
int gWalkImg[5]={0,0,0,0,0};
int gRanImg[7] = { 0,0,0,0,0,0,0};
int Movex = 0;	//動いた位置
int OPx = 0;	//元の位置
int MoveRunx = 0;
int OPxRun = 0;

int ImgRun = 0;	//条件に達するまでの少しの間同じ画像を表示し続ける用
int ImgWalk = 0;	//条件に達するまでの少しの間同じ画像を表示し続ける用
int wImg = 0;		//walkImgの画像どれ表示するかの表示

int RL = 0;	//左か右か判別する変数

/******************************************
 * プレイヤー初期化
 ******************************************/

Player::Player()
{
	gPlayer.flg = TRUE;
	gPlayer.x = PLAYER_POS_X;
	gPlayer.y = PLAYER_POS_Y;
	gPlayer.w = 120;
	gPlayer.h = 140;
	gPlayer.speed = PLAYER_SPEED;

}

Player::~Player()
{

}

void Player::PlayerInit(void) {
	gPlayer.flg = TRUE;
	gPlayer.x = PLAYER_POS_X;
	gPlayer.y = PLAYER_POS_Y;
	gPlayer.w = 120;
	gPlayer.h = 140;
	gPlayer.speed = PLAYER_SPEED;

	Poflg = 0;
}

int Player::LoadPlayerImg(void)
{
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
		if (app.PoHit() != 1) {
			//// 当たっていたらリンゴの色を白に
			//DrawString(0, 150, "HIt", 0xffffff);
			flg = 4;

			return TRUE;
		}
		
	}
	return FALSE;
}

/*************************************
 * プレイヤーの移動(XInput)
 *************************************/
void Player::PlayerXControl(XINPUT_STATE input, int& Pause_flg)
{
	if (InitFlg == 1) {
		InitFlg = 0;
		PlayerInit();
	}

	if (Pause_flg == 0)
	{
		// プレイヤーの左右移動
		// スティックをはじいたとき、値が戻らないため-20000と20000を設定している
		if (input.ThumbLX < -20000 || input.ThumbLX > 20000)
		{
			// 左移動
			// ダッシュ：Aボタンを押したまま左スティックを左に傾ける
			if (input.ThumbLX < -20000 && input.Buttons[XINPUT_BUTTON_A] == 1)
			{
				RL = 0;
				PlayerRan(RL);
				gPlayer.x -= gPlayer.speed + 2;
				MoveRunx = gPlayer.x;
			}
			// 歩く：左スティックを左に傾ける
			else if (input.ThumbLX < -20000)
			{

				RL = 0;
				PlayerWalk(RL);
				gPlayer.x -= gPlayer.speed;
				Movex = gPlayer.x;

			}

			// 右移動
			// ダッシュ：Aボタンを押したまま左スティックを右に傾ける
			if (input.ThumbLX > 20000 && input.Buttons[XINPUT_BUTTON_A] == 1)
			{
				RL = 3;
				PlayerRan(RL);
				gPlayer.x += gPlayer.speed + 2;
				MoveRunx = gPlayer.x;
			}
			// 歩く：左スティックを右に傾ける
			else if (input.ThumbLX > 20000)
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
			if (Poflg == 0) {
				//プレイヤー止まってる画像表示
				DrawExtendGraph(gPlayer.x - 10, gPlayer.y, gPlayer.x + gPlayer.w + 10, SCREEN_HEIGHT, gStopImg, TRUE);

			}
		}
	}
	else
	{
		//プレイヤー止まってる画像表示
		DrawExtendGraph(gPlayer.x-10, gPlayer.y, gPlayer.x + gPlayer.w+10, SCREEN_HEIGHT, gStopImg, TRUE);
}

	// 画面をはみ出さないようにする
	// 右
	if (gPlayer.x > 930)
	{
		ImgWalk=2;
		ImgRun = 3;
		Movex = gPlayer.x;
		OPxRun = MoveRunx;
		gPlayer.x = 930;
	}
	// 左
	if (gPlayer.x < 0)
	{

		ImgWalk = 0;
		ImgRun = 0;
		Movex = gPlayer.x;
		OPxRun = MoveRunx;
		gPlayer.x = 0;
	}

	mx0 = gPlayer.x;
	mx1 = mx0 + gPlayer.w;
	my0 = gPlayer.y;
	my1 = SCREEN_HEIGHT;

	HitPlayer();
}


//Playerの歩く動き
void Player::PlayerWalk(int wImg) {

	if (Poflg == 0) {

		if (abs(Movex - OPx) >= 31) {
			//一瞬画像が表示されなくなる時間ができるので表示
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[ImgWalk], TRUE);
			//OPxが動かなくならないように
			OPx = Movex;
		}
		else {
			//歩く動き
			switch (abs(Movex - OPx)) {
			case 10:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w , SCREEN_HEIGHT, gWalkImg[wImg], TRUE);
				ImgWalk = wImg;
				break;
			case 30:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[wImg + 1], TRUE);
				ImgWalk = wImg + 1;
				OPx = gPlayer.x;
				break;
			default:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[ImgWalk], TRUE);

			}

		}
	}


}

//Playerの走る動き
void Player::PlayerRan(int rImg)
{
	if (Poflg == 0) {

		if (abs(MoveRunx - OPxRun) >= 36) {
			/*OPxが動かなくならないように
			歩く動きからZで切り替えたとき、caseで判定できる数より、
			MoveRanx-OPxRanが大きい場合、画像が動かなくなってしまうので
			if文でリセットしている*/
			DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gWalkImg[ImgRun], TRUE);
			OPxRun = MoveRunx;
		}
		//走る動き
			switch (abs(MoveRunx - OPxRun)) {
			case 7:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg], TRUE);
				ImgRun = rImg;
				break;
			case 21:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 1], TRUE);
				ImgRun = rImg + 1;
				break;
			case 35:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[rImg + 2], TRUE);
				ImgRun = rImg + 2;
				OPxRun = gPlayer.x;
				break;
			default:
				DrawExtendGraph(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, gRanImg[ImgRun], TRUE);
			
		}
	}
	else {
		OPxRun = MoveRunx;
	}

}


//画像を点滅できるようにする
int Player::PlayerFlashing(void) {
	Poflg = 1;
	
		if (FlashCount < 121) {

			//120秒たつまで、20f感覚で点滅
			if (on > 0) {
				on -= 1;
				off = 20;
			}
			else if (off > 0) {
				Poflg = 0;
				off -= 1;
			}
			if (off == 0) {
				on = 20;
				Poflg = 1;
			}

		}

		if (FlashCount > 121)
		{
			Poflg = 0;
			app.Poget(0);
			on = 0;
			off = 0;
			FlashCount = 0;
		}

		FlashCount += 1;
	return 0;
}


void Player::Init(int Iflg)
{
	InitFlg = Iflg;
}