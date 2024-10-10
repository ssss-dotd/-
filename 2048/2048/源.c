#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // 游戏板的大小

// 函数声明
void initBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
void addRandomNumber(int board[SIZE][SIZE]);
int moveLeft(int board[SIZE][SIZE]);
int moveRight(int board[SIZE][SIZE]);
int moveUp(int board[SIZE][SIZE]);
int moveDown(int board[SIZE][SIZE]);
int canMove(int board[SIZE][SIZE]);
int checkWin(int board[SIZE][SIZE]);

// 主函数
int main() {
	int board[SIZE][SIZE];
	char command;

	srand(time(NULL)); // 初始化随机数生成器
	initBoard(board); // 初始化游戏板
	addRandomNumber(board); // 随机产生一个数字
	addRandomNumber(board);
	while (1) {
		printBoard(board); // 打印游戏板
		if (checkWin(board)) {
			printf("你赢了！\n");
			break;
		}
		if (!canMove(board)) {
			printf("游戏结束！无法移动。\n");
			break;
		}

		printf("输入移动方向 (w为向上，s为向下，a为向左，d为向右): ");
		scanf_s(" %c", &command, (unsigned)sizeof(command));

		int moved = 0; // 标记是否移动
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
			printf("无效命令，请输入 w/a/s/d。\n");
			continue;
		}

		if (moved) {
			addRandomNumber(board); // 移动后添加随机数
		}
	}

	return 0;
}

// 初始化游戏板
void initBoard(int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = 0; // 设置所有位置为0
		}
	}
}

// 打印游戏板
void printBoard(int board[SIZE][SIZE]) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0)
				printf(".\t"); // 0用.表示
			else
				printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// 在随机空位置生成2或4
void addRandomNumber(int board[SIZE][SIZE]) {
	int empty[SIZE * SIZE][2];
	int count = 0;

	// 找到所有空位置
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) {
				empty[count][0] = i;
				empty[count][1] = j;
				count++;
			}
		}
	}

	if (count > 0) // 没有空位
	{
		int randIndex = rand() % count;
		int value = (rand() % 2 + 1) * 2;   //随机生成2/4
		board[empty[randIndex][0]][empty[randIndex][1]] = value;
	}
}

// 向左移动
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

// 向右移动
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

// 向上移动
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

// 向下移动
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

// 判断是否可以移动
int canMove(int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0)
				return 1; // 还有空位可以移动
			if (j < SIZE - 1 && board[i][j] == board[i][j + 1])
				return 1; // 右边有相同的数字
			if (i < SIZE - 1 && board[i][j] == board[i + 1][j])
				return 1; // 下边有相同的数字
		}
	}
	return 0; // 无法移动
}

// 检查是否赢得游戏
int checkWin(int board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 2048)
				return 1; // 找到2048
		}
	}
	return 0; // 未找到2048
}