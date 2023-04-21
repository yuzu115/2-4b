#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__

/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
void PlayerInit(void);     // プレイヤー初期化
void PlayerControl(int oldkey, int gamemode);  // プレイヤー制御
void HitBoxPlayer(void);   // プレイヤーの当たり判定

#endif