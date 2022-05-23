#include<iostream>
#include<algorithm>
#include<memory.h>
#include<set>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, M, R;
std::set<int,std::greater<int>> graph[100001];
int visited[100001];
int order=1;

void dfs(int cur) {
	visited[cur] = order++;
	for (int next : graph[cur]) {
		if (visited[next]) continue;
		dfs(next);
	}
}

int main(){
	fastio;
	std::cin >> N >> M >> R;
	int u, v;
	for (int i = 0; i < M; i++) {
		std::cin >> u >> v;
		graph[u].emplace(v);
		graph[v].emplace(u);
	} 
	dfs(R);
	for (int i = 1; i <= N; i++) {
		std::cout << visited[i] << "\n";
	}
}