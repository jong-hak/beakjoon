#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, M;
int price[10];
std::string answer;


//그리디, 완전탐색    작은 수가 더 비싸거나 가격이 같으면 사용X 후 완전탐색
void solve(std::string num, int n, int m) {
	std::string temp = num;
	if (n == 0) {
		if (num.length() == 0) {
			temp = "0";
		}
		else{
			for (int i = 0; i < m / price[n]; i++)
				temp += '0';
		}

		if (temp.length() >= answer.length()) {
			answer = temp;
		}
		return;
	}
	solve(temp, n - 1, m);
	for (int i = 1; i <= m / price[n]; i++) {
		temp += (n + '0');
		solve(temp, n - 1, m - i * price[n]);
	}
}

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> price[i];
	}
	std::cin >> M;
	for (int i = 0; i < N - 1; i++) {
		for (int k = i + 1; k < N; k++) {
			if (price[i] >= price[k]) {
				price[i] = M+1;
				break;
			}
		}
	}
	solve("", N - 1, M);
	std::cout << answer;

}