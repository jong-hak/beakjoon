#include<iostream>
#include<algorithm>
#include<memory.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int sel[100001];
int visited[100001];
int len;

int dfs(int cur) {
	if (visited[sel[cur]]) return cur;
	visited[sel[cur]] = visited[cur] + 1;
	int con = dfs(sel[cur]);
	if (sel[con] == cur) {
		len = visited[con] - visited[cur] + 1;
	}
	return con;
}

int solve(int n) {
	memset(visited, 0, sizeof(int) * (n + 1));
	int sum = n;
	for (int i = 1; i <= n; i++) {
		if (sel[i] == i) {
			sum--;
			visited[i] = 1;
			continue;
		}
		if (visited[i]) continue;
		visited[i] = 1;
		len = 0;
		dfs(i);
		sum -= len;
	}
	return sum;
}

int main(){
	fastio;
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> sel[i];
		}
		std::cout << solve(n) << "\n";
	}

	return 0;
}