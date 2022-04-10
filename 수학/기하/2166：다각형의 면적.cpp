#include<iostream>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N;
std::pair<int, int> pos[10000];

int abs(int x) {
	if (x < 0) return -x;
	return x;
}

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> pos[i].first >> pos[i].second;
	}
	//10^5 * 10^5 이므로 int 범위 벗어남
	int result = 0;
	for (int i = 0; i < N; i++) {		//신발끈 공식
		result += pos[i].first * pos[(i + 1)%N].second;
		result -= pos[(i + 1)%N].first * pos[i].second;
	}
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << (double)abs(result) / 2;
}
