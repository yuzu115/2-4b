#pragma once

#ifndef TITLE_H__
#define TITLE_H__

//�^�C�g����ʂ݂̂Ŏg���ϐ��E�֐��̐錾�������ɏ����܂�

//�摜�ϐ��������ɏ����Ă�������

/*****************************************
*�@�v���g�^�C�v�錾
******************************************/
//void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode);		// �^�C�g����ʕ`��
int LoadTitleImages(void);		// �^�C�g���摜�Ǎ�

class TITLE
{
private:
	int TitleImg;			// �^�C�g���摜
	int AppleCursorImg;		// �J�[�\���i�ԃ����S�j�摜
	int menuNo;			// 0�FSTART�@1�FRANKING�@2�FHELP�@3�FEND
	int posY;				// �J�[�\����Y���W

public:
	TITLE();									// �R���X�g���N�^
	~TITLE();									// �f�X�g���N
	void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode);		// �^�C�g����ʕ`��
	//int LoadTitleImages(void);		// �^�C�g���摜�Ǎ�
};


void DrawTitle(int& GameMode);		// �^�C�g����ʕ`��

#endif // !TITLE_H__