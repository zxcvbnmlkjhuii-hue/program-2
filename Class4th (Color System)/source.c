#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


enum State
{
	IDLE,
	ATTAVK,
	DIE,

	// 열거형은 값을 따로 설정 할 수 있으며, 따로 설정된 값은 그 전의 값에서
	// 하나 증가된 값으로 설정됩니다.
};

void set(enum State state)
{
	switch (state)
	{
	case IDLE: printf("IDLE");
		break;
	case ATTAVK: printf("ATTAVK");
		break;
	case DIE: printf("DIE");
		break;
	default: printf("X");
	}

}

enum Color
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKSKYBLUE,
	DARKRED,
	DARKMAGENTA,
	DARKYELLOW,
	DARKWHITE,
	GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	MAGENTA,
	YELLOW,
	WHITE



};
int main()
{

#pragma region 열거형
	// 관려된 상수의 값을 이름으로 정의한 집합으로 자료형입니다.
//enum State state;

//state = IDLE;

//scanf_s("%d", &state);

//select(state);

#pragma endregion

	for (int i = 0; i < 16; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		if (i != 0 && i % 3 == 0)
		{
			system("pause");
		}
		printf("color system : %d\n", i);
	}


	return 0;
}

