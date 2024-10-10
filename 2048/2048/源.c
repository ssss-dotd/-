#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // ��Ϸ��Ĵ�С

// ��������
void initBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
void addRandomNumber(int board[SIZE][SIZE]);
int moveLeft(int board[SIZE][SIZE]);
int moveRight(int board[SIZE][SIZE]);
int moveUp(int board[SIZE][SIZE]);
int moveDown(int board[SIZE][SIZE]);
int canMove(int board[SIZE][SIZE]);
int checkWin(int board[SIZE][SIZE]);

// ������
int main() {
	int board[SIZE][SIZE];
	char command;

	srand(time(NULL)); // ��ʼ�������������
	initBoard(board); // ��ʼ����Ϸ��
	addRandomNumber(board); // �������һ������
	addRandomNumber(board);
	while (1) {
		printBoard(board); // ��ӡ��Ϸ��
		if (checkWin(board)) {
			printf("��Ӯ�ˣ�\n");
			break;
		}
		if (!canMove(board)) {
			printf("��Ϸ�������޷��ƶ���\n");
			break;
		}

		printf("�����ƶ����� (wΪ���ϣ�sΪ���£�aΪ����dΪ����): ");
		scanf_s(" %c", &command, (unsigned)sizeof(command));

		int moved = 0; // ����Ƿ��ƶ�
		switch (command) {
		case 'a':
			moved = moveLeft(board);
			break;
		case 'd':
			moved = moveRight(board);
			break;
		case 'w':
			moved = moveUp(board);
			break;
		case 's':
			moved = moveDown(board);
			break;
		default:
			printf("��Ч��������� w/a/s/d��\n");
			continue;
		}

		if (moved) {
			addRandomNumber(board); // �ƶ�����������
		}
	}

	return 0;
}

// ��ʼ����Ϸ��
void initBoard(int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = 0; // ��������λ��Ϊ0
		}
	}
}

// ��ӡ��Ϸ��
void printBoard(int board[SIZE][SIZE]) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0)
				printf(".\t"); // 0��.��ʾ
			else
				printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// �������λ������2��4
void addRandomNumber(int board[SIZE][SIZE]) {
	int empty[SIZE * SIZE][2];
	int count = 0;

	// �ҵ����п�λ��
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {
				empty[count][0] = i;
				empty[count][1] = j;
				count++;
			}
		}
	}

	if (count > 0) // û�п�λ
	{
		int randIndex = rand() % count;
		int value = (rand() % 2 + 1) * 2;   //�������2/4
		board[empty[randIndex][0]][empty[randIndex][1]] = value;
	}
}

// �����ƶ�
int moveLeft(int board[SIZE][SIZE]) {
	int moved = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (board[i][j] != 0) {
				int k = j;
				while (k > 0 && board[i][k - 1] == 0) {
					board[i][k - 1] = board[i][k];
					board[i][k] = 0;
					k--;
					moved = 1;
				}
				if (k > 0 && board[i][k - 1] == board[i][k]) {
					board[i][k - 1] *= 2;
					board[i][k] = 0;
					moved = 1;
				}
			}
		}
	}
	return moved;
}

// �����ƶ�
int moveRight(int board[SIZE][SIZE]) {
	int moved = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 2; j >= 0; j--) {
			if (board[i][j] != 0) {
				int k = j;
				while (k < SIZE - 1 && board[i][k + 1] == 0) {
					board[i][k + 1] = board[i][k];
					board[i][k] = 0;
					k++;
					moved = 1;
				}
				if (k < SIZE - 1 && board[i][k + 1] == board[i][k]) {
					board[i][k + 1] *= 2;
					board[i][k] = 0;
					moved = 1;
				}
			}
		}
	}
	return moved;
}

// �����ƶ�
int moveUp(int board[SIZE][SIZE]) {
	int moved = 0;
	for (int j = 0; j < SIZE; j++) {
		for (int i = 1; i < SIZE; i++) {
			if (board[i][j] != 0) {
				int k = i;
				while (k > 0 && board[k - 1][j] == 0) {
					board[k - 1][j] = board[k][j];
					board[k][j] = 0;
					k--;
					moved = 1;
				}
				if (k > 0 && board[k - 1][j] == board[k][j]) {
					board[k - 1][j] *= 2;
					board[k][j] = 0;
					moved = 1;
				}
			}
		}
	}
	return moved;
}

// �����ƶ�
int moveDown(int board[SIZE][SIZE]) {
	int moved = 0;
	for (int j = 0; j < SIZE; j++) {
		for (int i = SIZE - 2; i >= 0; i--) {
			if (board[i][j] != 0) {
				int k = i;
				while (k < SIZE - 1 && board[k + 1][j] == 0) {
					board[k + 1][j] = board[k][j];
					board[k][j] = 0;
					k++;
					moved = 1;
				}
				if (k < SIZE - 1 && board[k + 1][j] == board[k][j]) {
					board[k + 1][j] *= 2;
					board[k][j] = 0;
					moved = 1;
				}
			}
		}
	}
	return moved;
}

// �ж��Ƿ�����ƶ�
int canMove(int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0)
				return 1; // ���п�λ�����ƶ�
			if (j < SIZE - 1 && board[i][j] == board[i][j + 1])
				return 1; // �ұ�����ͬ������
			if (i < SIZE - 1 && board[i][j] == board[i + 1][j])
				return 1; // �±�����ͬ������
		}
	}
	return 0; // �޷��ƶ�
}

// ����Ƿ�Ӯ����Ϸ
int checkWin(int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 2048)
				return 1; // �ҵ�2048
		}
	}
	return 0; // δ�ҵ�2048
}