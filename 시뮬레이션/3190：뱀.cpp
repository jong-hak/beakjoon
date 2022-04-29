#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
#include<tuple>
#include<math.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N;
int board[100][100]; //0 ºó°ø°£, 1 ¹ì, 2 »ç°ú
int move[4][2] = { {-1,0},{0,1}, {1,0}, {0,-1} };
int direction;
int t;
std::queue<std::pair<int, char>> rotate;
std::deque<std::pair<int,int>> snake;

bool simulate() {

	int nr = snake.front().first+move[direction][0], nc= snake.front().second+move[direction][1];
	if (nr < 0 || nc < 0 || nr >= N || nc >= N || board[nr][nc] == 1) return false;
	
	if (board[nr][nc] == 0) {
		board[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	snake.emplace_front(nr, nc);
	board[nr][nc] = 1;

	if (!rotate.empty() && rotate.front().first == t) {
		direction += 4;
		if (rotate.front().second == 'L')
			--direction;
		else
			++direction;
		direction %= 4;
		rotate.pop();
	}
	t++;

	return true;
}

int solve() {

	while (simulate());
	return t;
}

int main()
{
	fastio;
	int k;
	std::cin >> N>>k;
	
	for (int i = 0; i < k; i++) {
		int r, c;
		std::cin >> r >> c;
		board[r-1][c-1] = 2;
	}
	int l;
	std::cin >> l;
	for (int i = 0; i < l; i++) {
		int a; char b;
		std::cin >> a ;
		std::cin >> b;
		rotate.emplace(a, b);
	}
	t = 1;
	direction = 1;
	board[0][0] = 1;
	snake.emplace_front(0, 0);

	std::cout << solve();

}