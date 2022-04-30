#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))


std::string str;
int data[200001][26];

int main()
{
	fastio;
	int q;
	std::cin >> str;
	std::cin >> q;
	for (int i = 1; i <= str.length(); i++) {
		for (int k = 0; k < 26; k++){
			data[i][k] = data[i - 1][k];
		}
		data[i][str[i-1] - 'a']++;
	}
	char a; 
	int l, r;
	while (q--) {
		std::cin >> a >> l >> r;
		std::cout << data[r + 1][a-'a'] - data[l][a-'a']<<"\n";
	}
	return 0;
}