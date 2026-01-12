#include <stdio.h>
#include <Windows.h>
#define SIZE 10
int main()
{
	const char * dialog[SIZE];

	dialog[0] = "사건 현장은 어디죠?";
	dialog[1] = "바로 이 방이에요.";
	dialog[2] = "문은 잠겨 있었습니까?";
	dialog[3] = "네. 안에서요.";
	dialog[4] = "그럼 누군가는, 열쇠를 다시 돌려놓았겠군요.";
	dialog[5] = "…그럴 리가 없어요.";
	dialog[6] = "불가능한 건 없습니다. 숨겨졌을 뿐이죠.";
	dialog[7] = "설마… 사고가 아니란 말인가요?";
	dialog[8] = "사고는 흔적을 남깁니다.";
	dialog[9] = "하지만 이건, 의도가 보입니다.";
	
	// 0x0000: 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	// 0x0001: 이전에 누른 적이 있고 호출 시점에도 눌려있지 않은 상태
	// 0x8000: 이전에 누른 적이 없고 호출 시점에도 눌려있는상태
	// 0x8001: 이전에 누른 적이 있고 호출 시점에도 눌려있는상태
	  

	while(1)
	{
		

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			int i = ;
			
			printf("%s\n", dialog[i]);
			int j= i + 1;
		}
	}
	

	//짝수 -> 탐정
	//홀수 -> 의뢰인

	return 0;
}