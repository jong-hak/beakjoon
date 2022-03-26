#include<iostream>
#include<algorithm>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

std::string s;

int pi[1000000];
int solve() {
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j-1];
		}
		if (s[j] == s[i])
			pi[i]=++j;
	}
	return s.size()  -pi[s.size()-1];
}

int main()
{
	fastio;
	int l;
	std::cin >> l;
	std::cin >> s;
	std::cout << solve();

	return 0;
}