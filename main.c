#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

// 본 프로그램은 visual studio 프로그램을 사용하여 개발되었습니다.
int main() {
	int M;
	int flag = 1;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int i, j, k, l, m, n, o;
	int index, type;
	int next_i, next_j;
	char next_game[4];

	printf("다운그레이드 버전 수박 게임!\n");
	Sleep(1000);
	printf("5X5 크기의 게임판에서 게임은 시작됩니다.\n");
	Sleep(1000);
	printf("A~G까지 랜덤한 알파벳이 생성됩니다.\n");
	Sleep(1000);
	printf("그 알파벳을 적절한 위치에 배치하십시오.\n");
	Sleep(1000);
	printf("만약, 앞, 뒤, 왼쪽, 오른쪽에 같은 알파벳이 있다면, 그 위치는 소멸합니다.\n");
	Sleep(1000);
	printf("판 위까지 알파벳이 배치된다면, 당신의 패배입니다.\n");
	Sleep(1000);

	while (1) {
		printf("그럼 게임을 시작합니다. 알파벳을 몇 번 배치하겠습니까? ");
		scanf("%d", &M);
		printf("%d회 동안 알파벳이 생성될 겁니다. 그럼 행운을 빕니다.\n", M);
		system("cls");

		int matrix[5][5] = {  // 게임판 생성
			{ '_', '_', '_', '_', '_' },
			{ '_', '_', '_', '_', '_' },
			{ '_', '_', '_', '_', '_' },
			{ '_', '_', '_', '_', '_' },
			{ '_', '_', '_', '_', '_' }
		};
	
		srand(time(NULL));

		for (i = 0; i < M; i++) {  // 게임판 출력
			for (n = 0; n < 5; n++) {
				for (o = 0; o < 5; o++) {
					printf("%c ", matrix[n][o]);
				}
				printf("\n\n");
			}
			printf("\n\n");
			type = rand() % 7 + 65;  // 랜덤으로 알파벳 생성
			printf("타입 : %c / x위치 : ", type);
			scanf("%d", &index);  // x좌표 입력받기
			index--;
			for (j = 4; j > -1; j--) {
				if (matrix[j][index] == '_') {
					matrix[j][index] = type;  // (index, y의 최솟값) 좌표로 알파벳 배치
					for (k = 0; k < 4; k++) {
						next_j = j + dy[k];
						next_i = index + dx[k];
						if (0 <= next_i && next_i < 5 && 0 <= next_j && next_j < 5) {  // 주변 위치 탐색
							if (matrix[next_j][next_i] == type) {  // 만약 주변 위치의 알파벳이 같다면
								matrix[j][index] = '_';  // 소멸
								matrix[next_j][next_i] = '_';
							}
						}
						for (l = 4; l > -1; l--) {
							for (m = j; m > 0; m--) {
								if (matrix[m][l] == '_' && matrix[m - 1][l] != '_') {  // 밑에 있는 알파벳이 없다면
									matrix[m][l] = matrix[m - 1][l];  // 한 칸 내리기
									matrix[m - 1][l] = '_';
								}
							}
						}
					}
					break;
				}
				else if (j == 0 && matrix[j][index] != '_') {  // 판이 다 찼다면
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				break;
			}
			system("cls");  // 화면 비우기
		}

		system("cls");

		for (i = 0; i < 5; i++) {  // 게임판 출력
			for (j = 0; j < 5; j++) {
				printf("%c ", matrix[i][j]);
			}
			printf("\n\n");
		}

		printf("\n");

		if (flag) {  // 성공 여부
			printf("성공!");
		}
		else {
			printf("패배!");
		}

		printf("\n다시 하시겠습니까? ([Y]es/[N]o) : ");
		scanf("%s", &next_game);  // 다시 할지 여부

		if (next_game[0] == 'Y' || next_game[0] == 'y') {  // Y라면 (다시 할 의향이 있다면)
			printf("잠시 후 게임을 초기화한 후 다시 실행합니다...");
			Sleep(3000);
			system("cls");  // 화면 초기화
			continue;  // 다시 실행
		}
		else {
			printf("플레이해주셔서 감사합니다!\n");
			Sleep(3000);
			break;  // 반복문 빠져나오고 코드 종료
		}
	}

	return 0;
}
