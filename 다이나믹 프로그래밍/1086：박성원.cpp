#include<iostream>
#include<algorithm>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, K;
std::string set[15];
int remain[51];
int remainS[15];
long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int mod(std::string& s) {
	int ans = 0;
	for (char c : s) {
		ans = (ans * 10 + c - '0') % K;
	}
	return ans;
}
long long memoi[1 << 15][100];
long long solve() {
	memoi[0][0] = 1;
	for (int i = 0; i < (1 << N); i++) {
		for (int k = 0, bit = 1; k < N; k++, bit <<= 1) {
			if (i & bit) continue;
			int next = bit | i;
			for (int j = 0; j < K; j++) {
				int r = ((j * remain[set[k].length()]) + remainS[k])%K;	//  현재 i만큼 사용한 상태에서 나머지가 j인것에 k를 추가한 경우의 나머지
															+=현재 i만큼 사용한 상태에서 나머지가 j인 것의 갯수
				memoi[next][r] += memoi[i][j];
			}
		}
	}
	return memoi[(1 << N) - 1][0];
}

long long fac(int n) {
	if (n <= 1) return 1;
	return n * fac(n - 1);
}

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> set[i];
	}
	std::cin >> K;

	std::string tmp = "1";
	for (int i = 0; i < N; i++) {
		remainS[i] = mod(set[i]);
	}
	for (int i = 0; i < 51; i++) {
		remain[i] = mod(tmp);
		tmp += '0';
	}


	long long total = fac(N);
	long long p = solve();
	if (p == 0) {
		std::cout << 0 << "/" << 1;
	}

	else {
		long long g = gcd(total, p);
		std::cout << p / g << "/" << total / g;
	}
}
