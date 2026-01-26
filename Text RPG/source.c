#include <stdio.h>
#include <conio.h>
#include <windows.h>
enum State
{
	Start,
	Plain,
	Tower,
	Action,
	Battle
};
struct Player
{
	char name[20];
	int hp;
	int attack;
	int defense;
	int level;
	int exp;
	int nextExp;
	int gold;

};
struct Monster
{
	char name[20];
	int hp;
	int attack;
	int defense;
	int level;
	int exp;
	int gold;
};

void ShowState()
{
	printf("무엇을 하시겠습니까\n");
	printf("1.평원을 간다\n");
	printf("2.타워을 간다\n");
	printf("3.마을에서 휴식을 한다\n");
}
void ShowPlain()
{
	printf("평원에 도착했습니다.\n");
	printf("1.탐색한다\n");
	printf("2.돌아간다\n");
}
void ShowPlayerState(struct Player player)
{
	printf("---------------------------------\n");
	printf("이름:%s\n", player.name);
	printf("체력:%d  ", player.hp);
	printf("공격력:%d  ", player.attack);
	printf("방어력:%d  \n", player.defense);
	printf("레벨:%d  ", player.level);
	printf("경험치:%d  ", player.exp);
	printf("필요 경험치:%d\n", player.nextExp);
	printf("골드:%d\n", player.gold);
	printf("---------------------------------\n");
}


void main()
{
	enum State state = Start;
	struct Player player = { "기사",100,10,3,1,0,100,50 };
	struct Monster monster;
	while (1)
	{
		switch (state)
		{
		case Start:
			ShowPlayerState(player);
			ShowState();

			int input = 0;
			scanf_s("%d", &input);
			if (input == 1)
			{
				state = Plain;
			}
			else if (input == 2)
			{
				state = Tower;
			}
			else if (input == 3)
			{
				printf("마을에서 휴식을 합니다\n");
				player.hp = 100;
			}
			break;
		case Plain:
			system("cls");
			ShowPlayerState(player);
			ShowPlain();
			 input = 0;
			scanf_s("%d", &input);
			if (input == 1)
			{
				state = Action;
			}
			else if (input == 2)
			{
				state = Start;
			}
			break;
		case Tower:
			system("cls");
			ShowPlayerState(player);
			printf("타워에 도착했습니다.\n");
			state = Start;
			break;
		case Action:
			monster = (struct Monster){ "슬라임",30,5,1,1,20,10 };
			system("cls");
			ShowPlayerState(player);
			printf("%s과 마주쳤습니다!\n",monster.name);
			state = Battle;
			break;
		case Battle:
			system("cls");
			ShowPlayerState(player);
			printf("전투를 시작합니다!\n");
		
			break;


		default:
			break;
		}
	}


}