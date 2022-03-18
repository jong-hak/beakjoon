#include<iostream>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long

ll sol[5000];
ll min = 30000000000;
int f, s, t;
//abs랑 std::abs 다름 , abs는 무조건 int로 들어가는듯?
void findMin(int third) {
	ll sum;
	int first = 0, second = third - 1;
	while (first < second) {
		sum = sol[first] + sol[second] + sol[third];
		if (min > std::abs(sum)) {
			min = std::abs(sum);
			f = first; s = second; t = third;
		}
		if (sum > 0) {
			second--;
		}
		else {
			first++;
		}
	}
}

int main()
{
	fastio;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> sol[i];
	}
	std::sort(sol, sol + N);
	for (int i = 2; i < N; i++) {
		findMin(i);
	}
	std::cout << sol[f] << " " << sol[s] << " " << sol[t];

}