#include<iostream>
#include<algorithm>
#include<memory.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

char board[10][10];
bool check_area[3][3][10];
bool check_row[9][10];
bool check_col[9][10];
bool complete;

void fill() {
	int num;
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			num = board[i][k] - '0';
			check_area[i / 3][k / 3][num] = true;
			check_row[i][num]= true;
			check_col[k][num] = true;

		}
	}
}

void solve(int r, int c) {
	if (r == 9) {
		complete = true;
		return;
	}
	if (board[r][c] == '0') {
		for (int i = 1; i <= 9; i++) {
			if (check_area[r/3][c/3][i] || check_row[r][i] || check_col[c][i]) continue;
			check_area[r/3][c/3][i] = check_row[r][i] = check_col[c][i] = true;
			board[r][c] = i+'0';
			solve((c + 1) / 9 + r, (c + 1) % 9);
			if (complete) return;
			board[r][c] = '0';
			check_area[r/3][c/3][i] = check_row[r][i] = check_col[c][i] = false;
		}
	}
	else {
		solve((c + 1) / 9 + r, (c + 1) % 9);
	}
}

int main(){
	fastio;
	for (int i = 0; i < 9; i++) {
		std::cin >> board[i];
	}
	fill();
	solve(0, 0);

	for (int i = 0; i < 9; i++) {
		std::cout << board[i] << "\n";
	}
	return 0;
}