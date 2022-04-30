#include<iostream>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int n,k;
int pSum[100000];

int main(){
	fastio;
	std::cin >> n >> k;
	std::cin >> pSum[0];
	int d;
	for (int i = 1; i < n; i++) {
		
		std::cin >> d;
		pSum[i] = pSum[i - 1] + d;
	}
	int ans = pSum[k-1], sum;
	for (int i = k; i < n; i++) {
		sum = pSum[i] - pSum[i - k];
		if (sum > ans) ans = sum;
	}
	std::cout << ans;
}