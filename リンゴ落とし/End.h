#pragma once

#ifndef END_H__
#define END_H__

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