#pragma once

#ifndef  HELP_H__
#define  HELP_H__

class Help
{
private:
	int HelpImg;				// �w���v�摜

public:
	Help();								// �R���X�g���N�^
	~Help();							// �f�X�g���N�^
	void DrawHelp(XINPUT_STATE input, int& Button_flg, int& GameMode);		// �w���v��ʕ`��
	int LoadHelpImages(void);			// �w���v�摜�Ǎ�
};

#endif // ! HELP_H__