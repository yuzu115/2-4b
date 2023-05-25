#include"DxLib.h"
#include"Keyboard.h"

#define ALPHA_MAX 26     // 入力出来る文字の種類の合計
#define CURSOR_X  240    // キーカーソルの初期位置X
#define CURSOR_Y  300    // キーカーソルの初期位置Y
#define KEY_WIDTH 60     //ノーマルキーの幅
#define KEY_HIGHT 60     //ノーマルキーの高さ

int gBackImg; // 背景画像
int gKeyImg[4];  // キーボード画像

//移動量   (キーボード〇番目)
int movekeyX = 0;
int movekeyY = 0;
CURSOR_TYPE CURSOR_NOW = CURSOR_TYPE::NORMAL;  //現在のカーソル
bool pushFlag = false;                         //Aが　押されている/押されてない フラグ    TRUE:押されている　FALSE:押されていない

int frame = 0;                   //フレームをカウント

char InputName[11];              //入力した文字が入る配列 0～9に文字(10文字ﾏﾃﾞ)　10番目には\0
int input_Pos;                   //入力中の配列の〇番目

// キーボードと同じ並びの配列
const char AllStr[5][ALPHA_MAX / 2 + 1] =
{
	"ABCDEFGHIJKLM",
	"NOPQRSTUVWXYZ",
	"abcdefghijklm",
	"nopqrstuvwxyz",
	"0123456789"
};


int LoadInpNameImg(void)
{
	// キーボード画像の読込
	if ((gKeyImg[0] = LoadGraph("images/キーボード.png")) == -1) return -1;
	// 背景画像の読込
	if ((gBackImg = LoadGraph("images/背景２.png")) == -1) return -1;

	return 0;
}

// キーボード初期化
void KeyBoardInit()
{
	//カーソルの初期位置は"A"
	movekeyX = 0;             //ｘ方向0番目
	movekeyY = 0;             //ｙ方向1番目

	//カーソルの初期位置は「A」なのでノーマル
	CURSOR_NOW = CURSOR_TYPE::NORMAL;

	//入力文字列　初期化
	for (int i = 0; i < 10; i++)
	{
		InputName[i] = 0;
	}
	InputName[10] = '\0';     //配列の一番最後に"\0"(終端の目印)を入れておく

	input_Pos = -1;

	pushFlag = FALSE;         //最初はAボタンは押されていない
}
//描画
void KeyBoard_Draw()
{
	// 背景画像の表示
	DrawExtendGraph(0, 0, 1280, 720, gBackImg, TRUE);
	// キーボード画像の表示
	DrawExtendGraph(200, 250, 1090, 650, gKeyImg[0], TRUE);

	// カーソルX
	int CurX = (CURSOR_X + KEY_WIDTH * movekeyX) + (2 * movekeyX);
	// カーソルY
	int CurY = CURSOR_Y + KEY_HIGHT * movekeyY;

	// ノーマル(A～Z,a～z,0～9)・「×」・「ＯＫ」によって画像変化　 switch文で操作
	switch (CURSOR_NOW)
	{
	case CURSOR_TYPE::NORMAL:    //ノーマルカーソル
		DrawCircle(CurX, CurY, 10, 0x2e8b57, TRUE);
		break;

	case CURSOR_TYPE::CANCEL:    //「×」カーソル
		DrawCircle(870, 540, 10, 0x2e8b57, TRUE);
		break;

	case CURSOR_TYPE::DONE:      //「OK」カーソル
		// OKキー選択カーソル画像の表示
		DrawCircle(580, 595, 10, 0x2e8b57, TRUE);
		break;

	default:
		break;
	}

	//入力中の文字を表示
	DrawInputInfo();
}

//更新
void KeyBoard_Update(XINPUT_STATE input, int& Button_flg)
{
	//フレーム数カウント
	frame++;

	if (input.ThumbLY > -2000 && input.ThumbLY < 2000 && input.Buttons[XINPUT_BUTTON_B] == 0)
	{
		Button_flg = FALSE;
	}
	if (input.ThumbLX > -2000 && input.ThumbLX < 2000 && input.Buttons[XINPUT_BUTTON_B] == 0)
	{
		Button_flg = FALSE;
	}

	//→ 右 
	if (input.ThumbLX > 2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		if (CursorControl() == true && CURSOR_NOW != CURSOR_TYPE::DONE)
		{
			movekeyX++;     //タイミング調整 + 移動
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);
			*/
		}
		if (movekeyX > 12) movekeyX = 0;   //右端以上で左端へ

		CURSOR_NOW = CURSOR_TYPE::NORMAL;  //現在のキーはノーマル
	}

	//← 左
	if (input.ThumbLX < -2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		if (CursorControl() == true)
		{
			movekeyX--;     //タイミング調整 + 移動
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);*/
		}
		if (movekeyX < 0) movekeyX = 12;     //左端以上で右端へ

		CURSOR_NOW = CURSOR_TYPE::NORMAL;    //現在のキーはノーマル
	}

	//↑ 上
	if (input.ThumbLY > 2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;

		if (CursorControl() == true)
		{
			
			movekeyY--;     //タイミング調整 + 移動
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);*/
		}
		if (movekeyY <= 0) movekeyY = 0;     //上端でストップ

		CURSOR_NOW = CURSOR_TYPE::NORMAL;         //現在のキーはノーマル
	}

	//↓ 下
	if (input.ThumbLY < -2000 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		if (CursorControl() == true)
		{
			
			movekeyY++;     //タイミング調整 + 移動
			/*ChangeNextPlayVolumeSoundMem(180, CursorMoveKeyboard);
			PlaySoundMem(CursorMoveKeyboard, DX_PLAYTYPE_BACK);*/
		}

		CURSOR_NOW = CURSOR_TYPE::NORMAL;         //現在のキーはノーマル
	}

	//「×」ボタン   「a～z」段より下 かつ 「9」キーより右側
	if (movekeyY == 4 && movekeyX >= 10)
	{
		movekeyX = 10;                       //ボタンの位置

		CURSOR_NOW = CURSOR_TYPE::CANCEL;         //現在のキーはキャンセル「×」
	}

	//「OK」ボタン   キーボード最下段より下
	if (movekeyY >= 5)
	{
		movekeyX = 0;                        //ボタンの位置
		movekeyY = 5;

		CURSOR_NOW = CURSOR_TYPE::DONE;           //現在のキーはDONE「OK」
	}

	DrawFormatString(0, 0, 0x000000, "Bflg:%d", input.Buttons[XINPUT_BUTTON_B]);
	DrawFormatString(0, 50, 0x000000, "Key:%d", CURSOR_NOW);

}

//カーソルの移動・ボタンの長押しを調整
bool CursorControl()
{
	int timing = 8;
	if (frame % timing == 0) return true;

	return false;
}

//Bボタンが押された時の処理
int KeyBoard_PushB(XINPUT_STATE input, char* name, int& Button_flg)
{
	//　Aボタンを押している間
	if (input.Buttons[XINPUT_BUTTON_B] == 1 )
	{
		
		//長押しでの連続入力のタイミングを調整（PCのような）
		if (CursorControl() == true)
		{
			// "A～Z","a～z","1～9"の上で押された
			//PlaySoundMem(ClickKeyboard, DX_PLAYTYPE_BACK);
			// "A～Z","a～z","1～9"の上で押された
			if (CURSOR_NOW == CURSOR_TYPE::NORMAL)
			{
				pushFlag = true;        //押されているよ

				++input_Pos;            //入力位置を一つ右に

				//上限は10文字   （配列の0～9）
				if (input_Pos > 9) input_Pos = 9;

				//文字配列に入力
				InputName[input_Pos] = AllStr[movekeyY][movekeyX];

			}
			else if (CURSOR_NOW == CURSOR_TYPE::CANCEL)                  //「×」キーの上で押された　一文字削除
			{
				pushFlag = true;        //押されているよ

				if (input_Pos >= 0)
				{
					//一文字でも入力されていれば一文字消す
					if (InputName[input_Pos] != 0) InputName[input_Pos] = 0; //0 は何も入力されていない状態

					input_Pos--;            //入力位置を一つ左に

					//入力位置は最低-1まで
					if (input_Pos < -1) input_Pos = -1;
				}

			}
			else if (CURSOR_NOW == CURSOR_TYPE::DONE)                  //「OK」キーの上で押された　確定
			{
				if (input_Pos >= 0)
				{
					//一文字も入力されていない場合は確定できない
					if (InputName[input_Pos] != 0)
					{
						//一文字でも入力アリ

						InputName[input_Pos + 1] = '\0';       //最後の文字の一つ右に'\0'

						//ランキングに入力内容をセット
						strcpy_s(name, 11, InputName);

						/*DeleteFontToHandle(key_font);
						StopSoundMem(KeyboardBGM);*/
						return 1;   //終了
					}
					else
					{
						//ダメだよ！　　な効果音
					}
				}
			}
		}
	}
	else
	{
		pushFlag = false;          //押されていないよ
	}

	if (input.Buttons[XINPUT_BUTTON_B] == 0)
	{
		Button_flg = FALSE;
	}

	return 0;
}


//入力情報表示
void DrawInputInfo()
{
	// 何も入力されてない
	if (InputName[0] == 0)
	{

		SetFontSize(23);
		DrawString(512, 148, "名前を入力してください", 0x616161);
	}

	// 入力された文字を表示
	for (int i = 0; InputName[i] != '\0'; i++)
	{
		SetFontSize(40);
		DrawFormatString(523 + 20 * i, 142, 0x616161, " %c", InputName[i]);
	}
}
