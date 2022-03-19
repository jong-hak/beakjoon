#include<iostream>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long

int R, C;
char board[20][20];

int move[4] = { 0,0,-1, 1};
int answer;
void dfs(int r, int c, int len ,int visited) {
	answer = std::max(answer, len);
	int nr, nc;
	for (int i = 0; i < 4; i++) {
		nr = move[i] + r; nc = move[3 - i] + c;
		if (nr < 0 || nc < 0 || nr >= R || nc >= C || (visited & (1<<board[nr][nc]))) continue;
		dfs(nr, nc, len + 1, visited | (1<<board[nr][nc]));
	}
}

int main()
{
	fastio;
	std::cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> board[i][j];
			board[i][j] -= 'A';
		}
	}
	dfs(0, 0, 1, 1<<board[0][0]);
	std::cout << answer;
}