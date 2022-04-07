#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<list>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N;
int parent[10001];
bool visited[10001];

int solve(int a, int b) {
	memset(visited, 0, N + 1);
	while (a != 0) {
		visited[a] = 1;
		a = parent[a];
	}
	while (!visited[b]) {
		b = parent[b];
	}
	return b;
}

int main()
{
	fastio;
	int T;
	int a, b;
	std::cin >> T;
	while (T--) {
		std::cin >> N;
		memset(parent, 0, sizeof(int) * (N + 1));
		for (int i = 0; i < N - 1; i++) {
			std::cin >> a >> b;
			parent[b] = a;
		}
		std::cin >> a >> b;
		std::cout << solve(a, b) << "\n";
	}

}