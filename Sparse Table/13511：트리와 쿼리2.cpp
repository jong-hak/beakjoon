#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long
int N;
std::vector<std::pair<int, ll>> graph[100001];
int rank[100001];
int parent[18][100001];
ll cost[100001];

void make_tree(int b, int c) {
	for (auto next : graph[c]) {
		if (next.first == b) continue;
		parent[0][next.first] = c;
		rank[next.first] = rank[c] + 1;
		cost[next.first] = cost[c] + next.second;
		make_tree(c, next.first);
	}
}
void make_sp() {
	for (int i = 1; i < 18; i++) {
		for (int k = 1; k <= N; k++) {
			parent[i][k] = parent[i - 1][parent[i - 1][k]];
		}
	}
}


int get_lca(int u, int v) {
	if (rank[u] < rank[v]) std::swap(u, v);
	if (rank[u] != rank[v]) {
		for (int i = 17; i >= 0; i--) {
			if (rank[parent[i][u]] > rank[v]) {
				u = parent[i][u];
			}
		}
		u = parent[0][u];
	}
	if (u == v) {
		return u;
	}
	for (int i = 17; i >= 0; i--) {
		if (parent[i][u] != parent[i][v]) {
			u = parent[i][u]; v = parent[i][v];
		}
	}
	return parent[0][u];
}
int get_k(int u, int v, int k) {
	int lca = get_lca(u, v);
	if (rank[u] - rank[lca] < k) {
		k -= rank[u] - rank[lca];
		k = rank[v] - rank[lca] - k;
		u = v;
	}
	for (int i = 0; i < 18; i++) {
		if ((1 << i) & k) u = parent[i][u];
	}
	return u;

}

int main() {
	fastio;
	std::cin >> N;
	int u, v, w;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}
	parent[0][1] = 1; rank[1] = 1;
	make_tree(1, 1);
	make_sp();
	int M;
	std::cin >> M;
	int n, k;
	while (M--) {
		std::cin >> n;
		if (n == 1) {
			std::cin >> u >> v;
			std::cout << cost[u]+cost[v]-2*cost[get_lca(u,v)] << "\n";
		}
		else {
			std::cin >> u >> v >> k;
			std::cout << get_k(u, v, k - 1) << "\n";
		}
	}
}