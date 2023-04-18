#pragma once
#include"DxLib.h"

//変数・関数・構造体などの 宣言 はヘッダーです
// 定義 は .cpp です
//a = 0; などデータを使いたいときは .cpp にかきます

/*** 命名規則（勝手に決めたので変えても◎）***/

// 変数名は小文字で始めましょう
// 関数名は大文字で始めましょう
// 定数名は全て大文字で書きましょう

/********************************************************************
*　定数の宣言
********************************************************************/
#define SCREENSIZE_X 1280
#define SCREENSIZE_Y 720

/******************************************
* 列挙型の宣言
******************************************/
enum mode {
	TITLE,
	INIT,
	MAIN,
	RANKING,
	HELP,
	INPUTNAME,
	RESULT,
	END,
	CLOSE,
};

/********************************************************************
*　変数の宣言
********************************************************************/
extern int g_OldKey;                  //前回の入力キー
extern int g_NowKey;                  //今回の入力キー
extern int g_KeyFlg;                  //入力キー情報

extern int GameMode;     //モード

int g_Score;      //スコア
