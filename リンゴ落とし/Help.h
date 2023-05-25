#pragma once

#ifndef  HELP_H__
#define  HELP_H__

class Help
{
private:
	int HelpImg;				// ヘルプ画像

public:
	Help();								// コンストラクタ
	~Help();							// デストラクタ
	void DrawHelp(XINPUT_STATE input, int& Button_flg, int& GameMode);		// ヘルプ画面描画
	int LoadHelpImages(void);			// ヘルプ画像読込
};

#endif // ! HELP_H__