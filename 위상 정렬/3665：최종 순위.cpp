#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

bool graph[501][501];
int ranking[500];
int indegree[501];
int n, m;
std::vector<int> answer;


bool solve() {
	bool visited[501] = {0,};
	std::queue<int> q;
	bool ambg=false;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			visited[i] = true;
			cnt++;
			if (cnt > 1)
				ambg = true;
		}
	}
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		answer.push_back(cur);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (graph[cur][i]) {
				indegree[i]--;
			}
			if (indegree[i] == 0 && !visited[i]) {
				cnt++;
				q.push(i);
				visited[i] = true;
				if (cnt > 1)
					ambg = true;
			}
		}
	}
	return ambg;
}

int main()
{
	fastio;
	int T;
	std::cin >> T;
	while (T--) {
		
		std::cin >> n;
		memset(indegree, 0, sizeof(int) * (n + 1));
		for (int i = 1; i <= n; i++) {
			memset(graph[i], 0, n + 1);
		}
		for (int i = 0; i < n; i++) {
			std::cin >> ranking[i];
		}
		for (int i = 0; i < n; i++) {
			for (int k = i + 1; k < n; k++) {
				graph[ranking[i]][ranking[k]] = 1;
				indegree[ranking[k]]++;
			}
		}
		std::cin >> m;
		int a, b;
		for (int i = 0; i < m; i++) {
			std::cin >> a >> b;
			if (graph[a][b] == 1) {
				graph[a][b] = 0;
				graph[b][a] = 1;
				indegree[a]++;
				indegree[b]--;
			}
			else {
				graph[a][b] = 1;
				graph[b][a] = 0;
				indegree[a]--;
				indegree[b]++;
			}
		}
		answer.clear();
		b = solve();
		if (answer.size() == n) {
			if (b) {
				std::cout << "?";
			}
			else {
				for (int i : answer) {
					std::cout << i << " ";
				}
			}

		}
		else {
			std::cout << "IMPOSSIBLE";
		}
		std::cout << "\n";
	}
}