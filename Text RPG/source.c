#include <stdio.h>
#include <conio.h>
#include <windows.h>




void ShowPlayer(int hp, int att, int dex)
{

	printf("------------------------------\n");
	printf("떠돌이 기사\n");
	printf("Hp : %d Att ; %d Dex : %d\n", hp, att, dex);
	printf("------------------------------\n");
}

void ShowAction()
{
	printf("1. 공격 \n");
	printf("2. 방어 \n");
}

void ShowMonster(char* name, int hp, int att, int dex)
{

	printf("------------------------------\n");
	printf("이름 : %s\n", name);
	printf("Hp : %d Att ; %d Dex : %d\n", hp, att, dex);
	printf("------------------------------\n");
}

int main() {
	char key;
	int playerLv = 1;
	int playerHp = 100;
	int playerAtt = 10;
	int playerDex = 5;


	int monsterHp = 50;
	int monsterAtt = 7;
	int monsterDex = 3;

	while (1)
	{
		system("cls");
		ShowPlayer(playerHp, playerAtt, playerDex);
		ShowAction();
		ShowMonster("늑대", monsterHp, monsterAtt, monsterDex);
		key = _getch();
		switch (key)
		{
		case 49:;
			printf("공격\n");
			if (playerAtt - monsterDex < 0)
			{
				printf("몬스터의 회피로 공격에 실패했습니다!\n");
				system("pause");
			}
			else
			{
				monsterHp -= playerAtt - monsterDex;
				printf("몬스터에게 %d의 데미지를 입혔습니다!\n", playerAtt - monsterDex);
				system("pause");
			}

			if (monsterHp <= 0)
			{
				printf("몬스터를 처치했습니다!\n");
				system("pause");
				break;
			}
			break;

		case 50:;
			printf("방어");
			if (monsterAtt - playerDex < 0)
			{
				printf("방어에 성광 했습니다!\n");
				system("pause");
			}
			else
				playerHp -= monsterAtt - playerDex;
			printf("몬스터에게서 %d의 데미지를 입었습니다!\n", monsterAtt - playerDex);
			system("pause");
			break;

		default: printf("잘못된 입력\n");
			system("pause");
			break;
		}
	}



	return 0;
}