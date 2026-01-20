#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


void position(int x, int y)
{
	COORD position = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position );

}

int main()
{
	
	
	char key = 0;
	int x = 5, y = 5;
	while (1)
	{
		system("cls");
		position(x, y);
		printf("★");

		int key = _getch();
		if (key == 224)
		{

			key = _getch();
			switch (key)
			{
			case UP:
				
				y--;
				break;
			case LEFT:
				
				x--;
				break;
			case RIGHT:
			
				x++;
				break;
			case DOWN:
			
				y++;
				break;
			default:
				
				
				break;
			}
		}
		else
		{
			
			
		}

		
		
	}

	
		// 커서의 위치를 이동시키는 함수

	return 0;
}

