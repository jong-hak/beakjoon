#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
#include<math.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, M;
char board[10][10];
struct Ball
{
	int red_r,red_c;
	int blue_r, blue_c;
};
int visited[10][10][10][10];
int move[2][4] = { {0,0,1,-1} , {1,-1,0,0} };
int hole_r, hole_c;

void simulate(Ball& b, int d) {
	bool front=true;
	while (board[b.red_r + move[0][d]][b.red_c + move[1][d]] != '#' && board[b.red_r][b.red_c] != 'O') {
		b.red_r += move[0][d], b.red_c += move[1][d];
		if (b.red_r == b.blue_r && b.red_c == b.blue_c)
			front = false;
	}
	while (board[b.blue_r + move[0][d]][b.blue_c + move[1][d]] != '#' && board[b.blue_r][b.blue_c] != 'O') b.blue_r += move[0][d], b.blue_c += move[1][d];
	if (b.red_r == b.blue_r && b.red_c == b.blue_c && board[b.blue_r][b.blue_c] != 'O') {
		if (front) {
			b.blue_r -= move[0][d]; b.blue_c -= move[1][d];
		}
		else {
			b.red_r -= move[0][d]; b.red_c -= move[1][d];
		}
	}
}

int solve(Ball base) {
	std::queue<Ball> q;
	q.push(base);
	visited[base.red_r][base.red_c][base.blue_r][base.blue_c] = 1;

	while (!q.empty()) {
		Ball b = q.front(); q.pop();
		int vCnt = visited[b.red_r][b.red_c][b.blue_r][b.blue_c];
		if (vCnt > 10) return -1;
		for (int i = 0; i < 4; i++) {
			Ball tmp = b;
			simulate(tmp, i);
			if (visited[tmp.red_r][tmp.red_c][tmp.blue_r][tmp.blue_c]) continue;
			if (tmp.blue_r == hole_r && tmp.blue_c == hole_c) continue;

			if (tmp.red_r == hole_r && tmp.red_c == hole_c) return vCnt;

			visited[tmp.red_r][tmp.red_c][tmp.blue_r][tmp.blue_c] = vCnt+ 1;
			q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	fastio;
	std::cin >> N >> M;
	Ball base;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			std::cin >> board[i][k];
			if (board[i][k] == 'R') base.red_r = i, base.red_c = k;
			else if (board[i][k] == 'B') base.blue_r = i, base.blue_c = k;
			else if (board[i][k] == 'O') hole_r = i, hole_c = k;
		}
	}
	std::cout<<solve(base);
}