#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__

/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
void PlayerInit(void);                            // プレイヤー初期化
void PlayerControl(int oldkey, int gamemode);     // プレイヤー制御
void GetApple(float ax0, float ay0, float ar0);         // リンゴの座標を変数に格納
void HitPlayer(void);                            // リンゴとプレイヤーの当たり判定
float Pythagorean(float px, float py, float ax, float ay);  // ピタゴラスの定理の計算
int LoadPlayerImg(void);       // 画像読込
#endif