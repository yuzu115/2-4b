#pragma once
#ifndef PAUSE_H_
#define PAUSE_H_

/************************
*関数のプロトタイプ宣言 *
************************/
void pause(int oldkey,int gamemode);//ポーズ画面遷移:@
void pausefinish(int keyflg, int gamemode);//ポーズ画面からゲームメインへ

#endif // !PAUSE_H_