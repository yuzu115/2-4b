#pragma once

#ifndef END_H__
#define END_H__

//�G���h��ʂ݂̂Ŏg���ϐ��E�֐��̐錾�������ɏ����܂�

//�摜�ϐ��������ɏ����Ă�������

/*****************************************
*�@�v���g�^�C�v�錾
******************************************/
//void DrawEnd(int& GameMode);		// �G���h��ʕ`��
//int LoadEndImages(void);			// �G���h�摜�Ǎ�

class End
{
private:
	int EndImg;					// �G���h�摜
	int EndWaitTime;			// �҂�����
	int PosY;					// �X�N���[�����̂x���W

public:
	End();								// �R���X�g���N�^	
	~End();								// �f�X�g���N�^
	void DrawEnd(int& gameMode);		// �G���h��ʕ`��
	int LoadEndImages(void);			// �G���h�摜�Ǎ�
};

#endif // !END_H__