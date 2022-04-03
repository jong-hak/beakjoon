#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, M;
std::vector<int> graph[32001];
int indegree[32001];
std::vector<int> answer;

void solve() {
	bool visited[32001] = { 0, };
	std::priority_queue<int,std::vector<int>, std::greater<int>> q;
	for (int i = 1; i <= N; i++) {
		if(indegree[i] == 0) {
			q.push(i);
			visited[i] = 1;
		}
	}
	int cur;
	while (!q.empty()) {
		cur = q.top(); q.pop();
		answer.push_back(cur);
		for (int next : graph[cur]) {
			indegree[next]--;
			if (!visited[next] && !indegree[next]) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}
}

int main()
{
	fastio;
	std::cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	solve();
	for (int i : answer) {
		std::cout << i << " ";
	}

}