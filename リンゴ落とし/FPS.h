#pragma once
#ifndef FPS_H_
#define FPS_H_

//関数のプロトタイプ宣言
void wait_fanc();//FPS固定処理の関数
void Reset_fps();//ループ前にFPS計測を初期化する関数
void Keisoku_fps();//FPSの計測する関数
void display_fps();//計測したFPSを表示する関数

#endif