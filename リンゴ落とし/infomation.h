#pragma once
#ifndef INFOMATION_H__
#define INFOMATION_H__

/******************************************
*　定数の宣言(マクロ定義)
*******************************************/
#define SCREENSIZE_X 1280
#define SCREENSIZE_Y 720

/******************************************
* 列挙型の宣言
******************************************/
enum mode {
	TITLE,
	INIT,
	MAIN,
	MAIN2,  // プレイヤー仮表示
	RANKING,
	HELP,
	INPUTNAME,
	RESULT,
	END,
	CLOSE,
};

#endif