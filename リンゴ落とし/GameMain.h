#pragma once
#ifndef GAMEMAIN_H_
#define GAMEMAIN_H_

/************************
*�֐��̃v���g�^�C�v�錾 *
************************/
void GameMain(int& GameMode, XINPUT_STATE input, int& Button_flg, int& Pause_flg);
void DrawUI(int& GameMode, int& FC, int& Pause_flg);
int LoadNumImg(void);
void GetAppCount(Apple::AppScore* as);

#endif // !GAMEMAIN_H_
