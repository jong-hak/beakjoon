#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<tuple>
#include<memory.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define INF 100000000

int M, N;
int visited[100][100];
bool maze[100][100];

struct cmp
{
	bool operator()(std::tuple<int, int, int>& a, std::tuple<int, int, int>& b) {
		return std::get<0>(a) > std::get<0>(b);
	}
};

int dijk() {
	int move[4][2] = { {0,1},{-1,0} ,{1,0} ,{0,-1} };
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++){
			visited[i][k] = INF;
		}
	}
	int r, c, nr, nc,cost;
	std::priority_queue<std::tuple<int,int,int>,std::vector<std::tuple<int, int, int>>,cmp> pq;	//부순 벽의 갯수, row,col 위치
	pq.emplace(0, 0, 0);
	visited[0][0] = 0;
	while (!pq.empty()) {
		std::tie(cost, r, c) = pq.top();
		if (r == N - 1 && c == M - 1) return cost;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + move[i][0]; nc = c + move[i][1]; 
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc]<= cost + maze[nr][nc]) continue;
			visited[nr][nc] = cost + maze[nr][nc];
			pq.emplace(cost + maze[nr][nc], nr, nc);
		}
	}
	return -1;
}

int main(){
	fastio;
	char s[101];
	std::cin >> M >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> s;
		for (int k = 0; k < M; k++) {
			maze[i][k] = s[k]-'0';
		}
	}
	std::cout << dijk();
	return 0;
}