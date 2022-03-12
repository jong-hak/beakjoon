#include<iostream>
#include<algorithm>

#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N;
int ability[20][20];
int memoi[20][1 << 20];

int dp(int p, int work) {
	if (p >= N) return 0;
	if (memoi[p][work]) return memoi[p][work];
	int min=200000;
	for (int i = 0,b=1; i < N; i++,b<<=1) {
		if (b & work) continue;
		min= std::min(min,dp(p + 1, work | b)+ability[p][i]);
	}
	return memoi[p][work] = min;
}

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			std::cin >> ability[i][k];
		}
	}
	std::cout << dp(0, 0);

}