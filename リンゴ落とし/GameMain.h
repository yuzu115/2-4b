#pragma once
#ifndef GAMEMAIN_H_
#define GAMEMAIN_H_
void GameMain(int& GameMode,XINPUT_STATE input, int& Button_flg,int& Pause_flg);

/************************
*�֐��̃v���g�^�C�v�錾 *
************************/
int LoadBackImg(void);
void DrawBack(void);

void DrawUI(int& GameMode, int& FC, int& Pause_flg);
int LoadNumImg(void);
#endif // !GAMEMAIN_H_