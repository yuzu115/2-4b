#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__

/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
void PlayerInit(void);                            // プレイヤー初期化
void PlayerControl(int gamemode);     // プレイヤー制御
void GetApple(float ax0, float ay0, float ar0);         // リンゴの座標を変数に格納
void HitPlayer(void);                            // リンゴとプレイヤーの当たり判定
float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
int PlayerFlashing(int& Count,int& on,int& off);
void PlayerWalk(int wImg);
void PlayerRan(int rImg);
int LoadImg(void);

void PlayerXControl(XINPUT_STATE input, int& Button_flg);     // プレイヤー制御(XInput)
void PlayerXIControl(XINPUT_STATE input);					 // プレイヤー制御(XInput)

#endif