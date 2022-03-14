#include<iostream>
#include<algorithm>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define DIV 1000000003
int N,K;

int dp[1000][1000][2]; //N번째 색, 선택한 수 갯수, 선택 여부

int cal(int start) {
	dp[0][start][start] = 1;
	dp[0][start ^ 1][start^1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1])%DIV;
			if(j!=K)
				dp[i][j + 1][1] = dp[i - 1][j][0];
		}
	}
	int ans = dp[N - 1][K][0];
	if (start == 0)
		ans =(ans+ dp[N - 1][K][1])%DIV;
	return ans;
}

int solve(){
	return (cal(0) + cal(1)) % DIV;
}

int main()
{
	fastio;
	std::cin >> N>>K;
	std::cout << solve();
}