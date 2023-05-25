#pragma once
#ifndef KEYBOARD_H__
#define KEYBOARD_H__

//�L�[�̎��
enum class CURSOR_TYPE
{
	NONE = 0,   // ����0�i�Ȃɂ�������Ă��Ȃ��j
	NORMAL,     // A�`B,a�`b,1�`9
	CANCEL,     //�u�~�v(�ЂƂ���)
	DONE,       //�uOK�v(�m��)

	MISS = 99
};

// �摜�ǂݍ���
int LoadInpNameImg(void);

//��������
void KeyBoardInit();

//�`��
void KeyBoard_Draw();

//�X�V
void KeyBoard_Update(int nowkey);

//�J�[�\���̈ړ��E�{�^���̒������𒲐�
bool CursorControl();

//B�{�^���������ꂽ���̏���  ���͂��I���� 1 ���Ԃ��Ă���
int KeyBoard_PushB(int nowkey, int& gamemode);

//���͏��\��
void DrawInputInfo();

#endif