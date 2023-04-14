#pragma once
#ifndef PLAYER_H__
#define PLAYER_H__
/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
void PlayerInit(void);     // プレイヤー初期化
void PlayerControl(int oldkey, int gamemode);  // プレイヤー制御

//int HitBoxPlayer(PLAYER* p);

#endif