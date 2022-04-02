#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int n, m;
std::vector<int> graph[32001];
bool visited[32001];

void dfs(int cur) {
	visited[cur] = 1;
	for (int next : graph[cur]) {
		if (!visited[next])
			dfs(next);	
	}
	std::cout << cur << " ";
}

int main()
{
	fastio;
	std::cin >> n >> m;
	int a,b;
	for (int i = 0; i < m; i++) {
		std::cin >> a>>b;
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) 
			dfs(i);
	}

	return 0;
}