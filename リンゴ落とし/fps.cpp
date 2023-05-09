#include"DxLib.h"
#include"math.h"
#include"FPS.h"

int count;
//FPSの計測と表示を行うローカル変数の宣言
LONGLONG nowTime = GetNowHiPerformanceCount();
LONGLONG oldTime = nowTime;
LONGLONG fpsCheckTime;
double deltaTime = 0;
int fpsCounter = 0;
int fps = 0;


void wait_fanc() {
	int term;
	static int t = 0;

	//現在の時間 - 1回前に取った時間で16秒まててるか調べる 
	term = GetNowCount() - t;

	if (16 - term > 0)
		Sleep(16 - term);

	t = GetNowCount();
	return;
}

void Reset_fps() {
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;
}

void Keisoku_fps() {
	///1ループ時点のシステム時間を取得
	oldTime = nowTime;
	nowTime = GetNowHiPerformanceCount();

	//1ループの時間経過を求める
	deltaTime = (nowTime - oldTime) / 6000000.0F;

	count += deltaTime;


	//1秒間のFPSを計測する、1秒ごとに初期化する
	fpsCounter++;
	if (nowTime - fpsCheckTime > 1000000) {
		fps = fpsCounter;
		fpsCounter = 0;
		fpsCheckTime = nowTime;
	}

}

void display_fps() {
	//FPSの表示
	SetFontSize(16);
	DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec", fps, deltaTime);

}