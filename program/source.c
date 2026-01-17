#include <stdio.h>
#include <stdlib.h>


void load(const char* fileName)
{

	FILE* file = fopen(fileName, "r");

	int count = 0;

	char c = NULL;

	while (c = fgetc(file) != EOF)
	{
		count++;
	}
	rewind(file);

	char* buffer = malloc(count + 1);

	buffer[count] = NULL;

	fread(buffer, sizeof(char), count, file);
	// 첫 번째 매개 변수 : 읽은 데잉터를 저장할 메모리 버퍼의 포인터 변수
	// 두 번째 매개 변수 : 각 데이터 항목의 크기
	// 세 번째 매개 변수 : 읽을 데이터 항목의 개수
	// 네 번째 매개 변수 : 파일 포인터 변수

	printf("%s", buffer);
	fclose(file);

	free(buffer);
}

int main()
{
#pragma region 파일 입출력
#pragma region 파일 쓰기
	// 첫 번쨰 매개 변수 (파일의 이름)
	// 두 번째 매개 변수 (파일을 입출력 모드)	
	//FILE* file = fopen("date.txt", "w");
	//
	//
	//fputs("Character Infirmation\n", file);
	//fputs("Health: \n ", file);
	//fputs("Attack: \n ", file);
	//fputs("Defense : ", file);

	//fclose(file);
#pragma endregion  파일 읽기 
	
	//load("Resources/Uint1.txt");

	

#pragma endregion

	return 0;
}
