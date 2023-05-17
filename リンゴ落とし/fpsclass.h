#pragma once

class FPSControll
{
public:
    FPSControll(float RefreshRate = 60.0f, int UpdateTime = 800);

    void Wait();     //�҂����Ԃ̌v�Z
    float Get();     //FPS�l�̌v�Z
    void Disp();     //�`�揈��

private:
    int frame_time;  //1�t���[���̎���(�~���b)
    int wait_time;   //�҂�����
    int last_time;   //�Ō�Ɏ擾�������Ԃ�
    int now_time;    //���̎���
    float count;     //�t���[���̃J�E���g
    float fps;       //�\�����邵��FPS�l
    int update_time; //�\���l���X�V���鎞��
    int last_update; //�Ō�ɕ\���l���X�V��������

    //�`��֌W�̕ϐ�
    int disp_x, disp_y;

    //������
    void Init(float RefreshRate, int UpdateTime);
};