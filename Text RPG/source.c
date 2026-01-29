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
	int maxhp;
	int hp;
	int attack;
	int defense;
	int level;
	int exp;
	int nextExp;
	int gold;
	int shield
		;
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
void ShowTower()
{
	printf("타워에 도착했습니다.\n");
	printf("1.탐색한다\n");
	printf("2.돌아간다\n");
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
	printf("체력:%d[%d]/%d  ", player.hp,player.shield,player.maxhp);
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
	struct Player player = { "기사",100,100,10,3,1,0,100,50,0 };
	struct Monster monster;
	enum Turn turn = PLAYER_TURN;
	srand(time(NULL));
	
	while (1)
	{
		switch (state)
		{
		case Start:
			system("cls");
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
				if (player.hp + 100 > player.maxhp)
					player.hp = player.maxhp;
				else
				player.hp += 100;
			}
			break;
		case Plain:
			system("cls");
			ShowPlayerState(player);
			ShowPlain();
			// 랜덤 몬스터 생성
			int PlainmonsterType = rand() % 2;

			if (PlainmonsterType == 1)
				monster = (struct Monster){ "슬라임",30,5,1,1,60,10 };
			else if (PlainmonsterType == 0)
				monster = (struct Monster){ "고블린",40,3,1,1,60,10 };

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
			ShowTower();
			// 랜덤 몬스터 생성
			int TowermonsterType = rand() % 2;
			if (TowermonsterType == 1)
				monster = (struct Monster){ "오크",100,7,2,2,120,20 };
			else if (TowermonsterType == 0)
				monster = (struct Monster){ "트롤",200,6,2,2,120,20 };
			input = 0;
			// 분기 선택
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
					
				}
				else if (input == 2)
				{
					player.shield += player.defense;
					system("cls");
					ShowPlayerState(player);
					ShowMonsterState(monster);
					system("pause");
				}
				else if (input == 3)
				{
					printf("마을로 이동 합니다.\n");
					state = Start;
					break;
				}
				
				turn = MONSTER_TURN;
			}
			 if (turn == MONSTER_TURN)
			{
				 srand(time(NULL));
				 int monsterAtkType = rand() %2;
				 if (monsterAtkType == 0)
				 {
					 
					 int atkDamage = monster.attack - player.shield; 
					 if (atkDamage < 0)
						 atkDamage = 0;
					 player.hp -= (atkDamage * 0.6)*3;
					 system("cls");
					 ShowPlayerState(player);
					 ShowMonsterState(monster);
					 printf("%s의 연속공격! %d=(%d*0.6)*3-%d!\n", monster.name, atkDamage,monster.attack,player.shield);
					 system("pause");
					 
				 }
				 else if (monsterAtkType == 1)
				 {
					 int atkDamage = monster.attack - player.shield;
					 if (atkDamage < 0)
						 atkDamage = 0;
					 player.hp -= atkDamage ;
					 system("cls");
					 ShowPlayerState(player);
					 ShowMonsterState(monster);
					 printf("%s의 일반공격! %d=%d-%d!\n", monster.name, atkDamage, monster.attack, player.shield);
					 system("pause");
				 }

				 turn = PLAYER_TURN;
			}
			 // 몬스터 처치
			 if (monster.hp <= 0)
			 {
				 printf("%s를 물리쳤습니다!\n", monster.name);
				 player.exp += monster.exp;
				 printf("경험치 %d 획득!\n", monster.exp);
				 system("pause");
				 // 레벨업 체크
				 if (player.exp > player.nextExp)
				 {
					 player.level += 1;
					 player.exp = player.exp - player.nextExp;
					 player.nextExp += 100;
					 player.attack += 5;
					 player.defense += 2;
					 player.maxhp += 20;
					 printf("레벨업! 현재 레벨 %d\n", player.level);
					 system("pause");
				 }
				 player.gold += monster.gold;
				 printf("골드 %d 획득!\n", monster.gold);
				 printf("마을로 이동 합니다.\n");
				 state = Start;
				 break;	
			 }
			 // 플레이어 사망
			 if (player.hp <= 0)
			 {
				 printf("당신은 죽었습니다...\n");
				 printf("게임을 종료합니다.\n");
				 system("pause");
				 return;
			 }
			 player.shield = 0;
			printf("전투를 시작합니다!\n");
			state = Battle;
			
		}
	}


}



//o 1. 유닛생산
//o 2. 유닛의 현재 상태 출력
//o 3. 랜덤한 유닛 생성 -> X싸움중 마을로 돌아가면 다시 랜덤 유닛 생성
//o 4. 유닛간의 전투 
//o 5. 유닛간의 전투 중 랜덤 이벤트 발생 (크리티컬, 회피 등)
//o 6. 유닛 경험치 및 레벨업 시스템
//  7, 인벤토리 만들기	(아이템 사용, 장착 등)
//  8. 상점 시스템 (아이템 구매 등)
// 9. 스킬 시스템 (스킬 사용 등)
// 10.몬스터 처치지 아이템 드랍