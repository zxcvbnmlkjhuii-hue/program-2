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
enum Turn
{
	PLAYER_TURN,
	MONSTER_TURN
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
	printf("레벨:%d  ", player.level);
	printf("경험치:%d  ", player.exp);
	printf("필요 경험치:%d\n", player.nextExp);
	printf("체력:%d  ", player.hp);
	printf("공격력:%d  ", player.attack);
	printf("방어력:%d  \n", player.defense);
	printf("골드:%d\n", player.gold);
	printf("---------------------------------\n");
}

void ShowMonsterState(struct Monster monster)
{
	printf("---------------------------------\n");
	printf("이름:%s\n", monster.name);
	printf("레벨:%d  \n", monster.level);
	printf("체력:%d  ", monster.hp);
	printf("공격력:%d  ", monster.attack);
	printf("방어력:%d  \n", monster.defense);
	printf("---------------------------------\n");
}

void ShowBattle()
{
	printf("1.공격한다\n");
	printf("2.방어한다\n");
	printf("3.도망친다\n");
}

void main()
{
	enum State state = Start;
	struct Player player = { "기사",100,10,3,1,0,100,50 };
	struct Monster monster;
	enum Turn turn = PLAYER_TURN;
	srand(time(NULL));
	int PlainmonsterType = rand() % 2;
	if (PlainmonsterType == 1)
		monster = (struct Monster){ "슬라임",30,5,1,1,20,10 };
	else if (PlainmonsterType == 0)
		monster = (struct Monster){ "고블린",40,3,1,1,20,10 };
	int random = rand();
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

			system("cls");
			ShowPlayerState(player);
			printf("%s과 마주쳤습니다!\n", monster.name);
			state = Battle;
			break;
		case Battle:
			system("cls");
			ShowPlayerState(player);
			ShowMonsterState(monster);
			ShowBattle();

			if (turn == PLAYER_TURN)
			{
				input = 0;
				scanf_s("%d", &input);
				if (input == 1)
				{
					monster.hp -= player.attack;
					break;
				}
				else if (input == 2)
				{

				}
				else if (input == 3)
				{
					state = Start;
					printf("마을로 이동 합니다.\n");
					break;
				}
				turn = MONSTER_TURN;
			}
			else if (turn == MONSTER_TURN)
			{

			}

		
			printf("전투를 시작합니다!\n");
		
			break;


		default:
			break;
		}
	}


}



//o 1. 유닛생산
//o 2. 유닛의 현재 상태 출력
// 3. 랜덤한 유닛 생성
// 4. 유닛간의 전투 
// 5. 유닛간의 전투 중 랜덤 이벤트 발생 (크리티컬, 회피 등)