#pragma once
#ifndef KEYBOARD_H__
#define KEYBOARD_H__

//キーの種類
enum class CURSOR_TYPE
{
	NONE = 0,   // 入力0（なにも押されていない）
	NORMAL,     // A～B,a～b,1～9
	CANCEL,     //「×」(ひとつ消す)
	DONE,       //「OK」(確定)

	MISS = 99
};

// 画像読み込み
int LoadInpNameImg(void);

//初期処理
void KeyBoardInit();

//描画
void KeyBoard_Draw();

//更新
void KeyBoard_Update(int nowkey);

//カーソルの移動・ボタンの長押しを調整
bool CursorControl();

//Bボタンが押された時の処理  入力が終わると 1 が返ってくる
int KeyBoard_PushB(int nowkey, int& gamemode);

//入力情報表示
void DrawInputInfo();

#endif