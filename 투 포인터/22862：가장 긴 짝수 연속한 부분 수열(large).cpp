#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, K;
int seq[1000000];

int solve() {
	int j = -1, oddNum=0;
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (seq[i] % 2) {
			oddNum++;
			if (oddNum > K) {
				while (seq[++j] % 2==0);
				oddNum--;
			}
		}
		max = std::max(max, i - j-oddNum);
	}


	return max;
}

int main()
{
	fastio;
	std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		std::cin >> seq[i];
	}
	std::cout << solve();
}