#pragma once

#ifndef TITLE_H__
#define TITLE_H__

class Title
{
private:
	int TitleImg;			// �^�C�g���摜
	int AppleCursorImg;		// �J�[�\���i�ԃ����S�j�摜
	int menuNo;				// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEND
	int posY;				// �J�[�\����Y���W

public:
	Title();									// �R���X�g���N�^
	~Title();									// �f�X�g���N
	void DrawTitle(XINPUT_STATE input, int& button_flg, int& gameMode);		// �^�C�g����ʕ`��
	int LoadTitleImages(void);		// �^�C�g���摜�Ǎ�
};

#endif // !TITLE_H__