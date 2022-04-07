#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<list>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int m;
int f[200001];
int sparse_talble[20][200001];

int solve(int n, int x) {
	for (int i = 19; i >= 0; i--) {
		if (n >= (1 << i)) {
			x = sparse_talble[i][x];
			n -= 1 << i;
		}
	}
	return x;
}

int main()
{
	fastio;
	std::cin >> m;

	for (int i = 1; i <= m; i++) {
		std::cin >> f[i];
	}
	for (int i = 1; i <= m; i++) {
		sparse_talble[0][i] = f[i];
	}
	for (int i = 1; i < 20; i++) {
		for (int k = 1; k <= m; k++) {
			sparse_talble[i][k] = sparse_talble[i - 1][sparse_talble[i - 1][k]];
		}
	}
	int Q,n,x;
	std::cin >> Q;
	while (Q--) {
		std::cin >> n >> x;
		std::cout << solve(n, x) << "\n";
	}

}