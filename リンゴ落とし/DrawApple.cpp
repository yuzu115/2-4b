#include"DxLib.h"
#include"DrawApple.h"

int AppleY = 0;

void DrawApple(void)
{
	DrawCircle(640, AppleY, 45, 0xffffff, TRUE);

	if (AppleY < 500){
		for (int i = 0; i < 3; i++)
		{
			AppleY += 3;
			DrawFormatString(0, 20,0x000000, "%d", AppleY);
		}

	}
	
	if (AppleY > 500){
		AppleY = 0;
	}


}