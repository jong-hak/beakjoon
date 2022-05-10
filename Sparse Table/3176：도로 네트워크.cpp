#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<tuple>
#include<memory.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N,K;

//해당 노드부터 부모까지 사이에서의 최대, 최소
int s_max[18][100001];
int s_min[18][100001];

int sparse_tree[18][100001];
std::pair<int,int> parent[100001];
std::vector<std::pair<int, int>> graph[100001];
int rank[100001];

//그래프로 트리 생성
void make_tree(int before, int node) {
	parent[node].first = before;
	for (auto& next : graph[node]) {
		if (next.first == before) continue;
		rank[next.first] = rank[node] + 1;
		parent[next.first].second = next.second;
		make_tree(node,next.first);
	}
}

//공통 조상 찾으면서 사이의 최대, 최소 구하기
void solve(int a, int b) {
	int max=-1, min=1000001;
	if (rank[a] < rank[b]) std::swap(a, b);
	if (rank[a] > rank[b]) {
		for (int i = 17; i >= 0; i--) {
			if (rank[sparse_tree[i][a]] > rank[b]) {
				max = std::max(s_max[i][a], max);
				min = std::min(s_min[i][a], min);
				a = sparse_tree[i][a];
			}
		}
		max = std::max(s_max[0][a], max);
		min = std::min(s_min[0][a], min);
		a = sparse_tree[0][a];
	}
	if (a != b) {
		for (int i = 17; i >= 0; i--) {
			if (sparse_tree[i][a] != sparse_tree[i][b]) {
				max = std::max({ max, s_max[i][a], s_max[i][b] });
				min = std::min({ min, s_min[i][a], s_min[i][b] });
				a = sparse_tree[i][a]; b = sparse_tree[i][b];
			}
		}
		max = std::max({ max, s_max[0][a], s_max[0][b] });
		min = std::min({ min, s_min[0][a], s_min[0][b] });
	}
	std::cout << min << " " << max << "\n";
}

int main(){
	fastio;
	std::cin >> N;
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	make_tree(1,1);
	for (int i = 1; i <= N; i++) {
		sparse_tree[0][i] = parent[i].first;
		s_max[0][i] = parent[i].second;
		s_min[0][i] = parent[i].second ? parent[i].second : 1000001;
	}
	for (int i = 1; i < 18; i++){
		for (int k = 1; k <= N; k++) {
			sparse_tree[i][k] = sparse_tree[i-1][sparse_tree[i-1][k]];
			s_max[i][k] = std::max(s_max[i-1][k], s_max[i-1][sparse_tree[i-1][k]]);
			s_min[i][k] = std::min(s_min[i - 1][k], s_min[i - 1][sparse_tree[i - 1][k]]);
		}
	}
	std::cin >> K;
	int d, e;
	while (K--) {
		std::cin >> d >> e;
		solve(d, e);
	}

	return 0;
}