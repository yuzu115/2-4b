#pragma once

#ifndef PLAYER_H__
#define PLAYER_H__

#include "DrawApple.h"

/******************************************
 * 定数の宣言
 ******************************************/
 // 画面サイズ
const int SCREEN_WIDTH = 1280;   // 幅
const int SCREEN_HEIGHT = 720;    // 高さ

 // プレイヤーの初期値の定数
const int PLAYER_POS_X = 600;  // X座標 
const int PLAYER_POS_Y = 570;  // Y座標 
const int PLAYER_SPEED = 5;    // 移動速度

/******************************************
 * 構造体の宣言
 ******************************************/
 // プレイヤーの構造体




/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
void PlayerInit(void);                            // プレイヤー初期化
void PlayerControl(int oldkey, int gamemode);     // プレイヤー制御
//void GetApple(int ax0, float ay0, int ar0,float size);         // リンゴの座標を変数に格納
int HitPlayer(Apple::APPLE_DATE *a, Player::PLAYER *p);                        // リンゴとプレイヤーの当たり判定
float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算


class Player
{
public:
	typedef struct
	{
		int flg;       // 使用フラグ
		float x, y;      // 座標
		int w, h;      // 幅、高さ
		int speed;     // 移動速度

	}PLAYER;

};
#endif