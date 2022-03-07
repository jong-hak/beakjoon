#include<iostream>
#include<vector>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N;
int population[10001];
std::vector<int> edge[10001];
int memoi[10001][2];


int solve(int before, int current, int selct) {
	int sum=0;
	if (memoi[current][selct]) return memoi[current][selct];
	if (selct) {
		for (int v : edge[current]) {
			if (v == before) continue;
			sum+=solve(current, v, 0);
		}
	}
	else {
		for (int v : edge[current]) {
			if (v == before) continue;
			sum +=std::max(solve(current, v, 0), solve(current, v, 1)+population[v]);
		}
	}
	return memoi[current][selct] = sum;
}


int main()
{
	fastio;
	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		std::cin>>population[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b;
		edge[a].push_back(b); edge[b].push_back(a);
	}
	edge[0].push_back(1);
	std::cout << solve(0, 0, 0);

}