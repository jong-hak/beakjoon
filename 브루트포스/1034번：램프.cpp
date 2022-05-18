#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, M,k;
std::unordered_map<std::string, int> row;

int solve() {
	int max = 0;
	for (const auto& e : row) {
		int cnt = 0;
		for (char c : e.first) {
			if (c == '0') cnt++;
		}
		if (cnt > k) continue;
		if ((k - cnt) % 2) continue;
		max = std::max(max, e.second);
	}
	return max;
}

int main()
{
	fastio;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::string col;
		std::cin >> col;
		if (row.find(col) == row.end()) {
			row.emplace(col, 1);
		}
		else {
			row[col]++;
		}
	}
	std::cin >> k;
	std::cout << solve();
	return 0;
}