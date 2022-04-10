#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<math.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long

ll min, max;
bool numbers[1000001];

void find() {
	for (ll i = 2; i <= sqrt(max); i++) {
		ll p = i * i;
		for (ll k = ((min+p-1)/p)*p ; k <= max; k += p) {
			numbers[k - min] = true;
		}
	}
}

int main()
{
	fastio;
	std::cin >> min >> max;
	find();
	int cnt = 0;
	for (int i = 0; i < max - min + 1; i++) {
		if (!numbers[i]) cnt++;
	}
	std::cout << cnt;
}