#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int tab[20][40]) { // printing the board
	int i, j;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (tab[i][j] == 1) {
				printf("#");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
}
void init_board(int tab[20][40]) { // initiating the board by filling with dead cells
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 40; j++) {
			tab[i][j] = 0;
		}
	}
}
void seed_board(int tab[20][40]) { // filling the board with random seed
	int i, j;
	srand(time(NULL));
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 40; j++) {
			tab[i][j] = rand() % 2;
		}
	}
}
int count_neighbours(int tab[20][40], int curr_r, int curr_c) { // counting neighbours of a cell
	int count = 0;
	int i, j;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			int ni = curr_r + i;
			int nj = curr_c + j;
			if (ni >= 0 && ni < 20 && nj >= 0 && nj < 40) {
				if (tab[ni][nj]) {
					count++;
				}
			}
		}
	}
	return count - tab[curr_r][curr_c];
}
void update_board(int tab[20][40]) { // updating the board with next generation
	int new_board[20][40];
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 40; j++) {
			int n = count_neighbours(tab, i, j);
			if (tab[i][j] == 1) {
				if (n < 2 || n > 3) {
					new_board[i][j] = 0;
				}
				else {
					new_board[i][j] = 1;
				}
			}
			else {
				if (n == 3) {
					new_board[i][j] = 1;
				}
				else {
					new_board[i][j] = 0;
				}
			}
		}
	}
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 40; j++) {
			tab[i][j] = new_board[i][j];
		}
	}
}

int main() {
	int i, j;
	int board[20][40]; // board of cells
	int next_button = 0; // button for continuing generating generations
	printf("Welcome to the Life Simulator\n");
	init_board(board);
	printf("First generation:\n");
	seed_board(board);
	print_board(board);
	getchar();
	system("cls");
	printf("Next generation:\n");
	update_board(board);
	print_board(board);
	printf("Do you want to generate another generation? For yes press 1, for no press 0: ");
	scanf_s("%d", &next_button);
	while (next_button) {
		system("cls");
		printf("Next generation:\n");
		update_board(board);
		print_board(board);
		printf("For another generation press 1, for closing program press 0: ");
		scanf_s("%d", &next_button);
	}
	printf("\nThe end of simulation\n");
	return 0;
}