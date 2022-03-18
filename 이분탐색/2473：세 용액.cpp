#include<iostream>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long

ll sol[5000];
ll min = 3000000000;
ll ans[3];
int N;

void bs(int i, int k) {
	int s = k+1, e = N - 1,mid;
	ll total;
	while (s <= e) {
		mid = (s + e) / 2;
		total = sol[i] + sol[k] + sol[mid];
		
		if (std::abs(total) < min) {
			min = std::abs(total);
			ans[0] = sol[i]; ans[1] = sol[k]; ans[2] = sol[mid];
		}

		if (total > 0) 
			e = mid - 1;
		else
			s = mid + 1;
	}
	
}

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> sol[i];
	}
	std::sort(sol, sol + N);

	for (int i = 0; i < N - 2; i++) {
		for (int k = i + 1; k < N - 1; k++) {
			 bs( i,k);
		}
		if (min == 0) break;
	}

	std::cout << ans[0] << " " << ans[1] << " " << ans[2];

}