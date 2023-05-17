#include"DxLib.h"
#include"fpsclass.h"

//�R���X�g���N�^
FPSControll::FPSControll(float RefreshRate, int UpdateTime)
{
    Init(RefreshRate, UpdateTime);
}

//������
void FPSControll::Init(float RefreshRate, int UpdateTime)
{
    frame_time = (int)(1000.0f / RefreshRate); //1�t���[���̎��Ԃ̌v�Z
    update_time = UpdateTime;
    wait_time = 0;
    last_time = now_time = 0;
    count = 0.0f;
    fps = 0.0f;
    last_update = 0;
    //�`��֌W
    disp_x = 0;
    disp_y = 0;
}

//�҂����Ԃ̌v�Z
void FPSControll::Wait()
{
    now_time = GetNowCount();
    wait_time = frame_time - (now_time - last_time);

    //�҂����Ԃ������
    if (wait_time > 0)
    {
        WaitTimer(wait_time); //�w�莞�ԑ҂�
    }
    last_time = GetNowCount();
}

//FPS�l�̌v�Z
float FPSControll::Get()
{
    count += 1.0f;
    if (update_time < (last_time - last_update))
    { //�A�b�v�f�[�g���ԂɂȂ��Ă����
        fps = count / (float)(last_time - last_update) * 1000.0f; //FPS�l�̌v�Z
        last_update = last_time;
        count = 0.0f;
    }
    return (fps);
}

//�`�揈��
void FPSControll::Disp()
{
    DrawFormatString(disp_x, disp_y, 0xffffff, "fps:%0.1f", fps);
}