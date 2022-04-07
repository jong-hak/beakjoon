#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<list>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N,M;
int parent[100001];
int rank[100001];
int sparse_table[17][100001];
std::vector<int> graph[100001];

void get_tree(int before, int current,int d) {
	parent[current] = before;
	rank[current] = d;
	for (int next : graph[current]) {
		if (next == before) continue;
		get_tree(current, next,d+1);
	}
}

int LCA(int a, int b) {
	
	if (rank[a] < rank[b]) {
		std::swap(a, b);
	}
	if (rank[a] != rank[b]) {
		for (int i = 16; i >= 0; i--) {
			if (rank[sparse_table[i][a]] >= rank[b]) {
				a = sparse_table[i][a];
			}
		}
	}
	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {
		if (sparse_table[i][a] != sparse_table[i][b]) {
			a = sparse_table[i][a];
			b = sparse_table[i][b];
		}
	}
	return parent[a];
}

int main()
{
	fastio;
	std::cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	get_tree(1,1,0);
	for (int i = 1; i <= N; i++) {
		sparse_table[0][i] = parent[i];
	}
	for (int i = 1; i < 17; i++) {
		for (int k = 1; k <= N; k++) {
			sparse_table[i][k] = sparse_table[i - 1][sparse_table[i - 1][k]];
		}
	}
	std::cin >> M;
	while (M--) {
		std::cin >> a >> b;
		std::cout << LCA(a, b)<<"\n";
	}
}