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
			j++;
		pi[i] = j;
	}
	int l = s.size() - pi[s.size() - 1];
	if (s.size() % l != 0) return 1;
	return s.size() / l;
}

int main()
{
	fastio;
	while(1) {
		std::cin >> s;
		if (s[0] == '.') break;
		std::cout << solve()<<"\n";
	}

	return 0;
}