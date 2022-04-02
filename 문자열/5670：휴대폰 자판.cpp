#include<iostream>
#include<algorithm>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

struct Trie
{
	int cnt;
	bool flag;
	Trie* next[26];
	Trie() {
		flag = false;
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}

	void add(char* c) {
		if (*c == 0) {
			flag = true;
		}
		else {
			int cur = *c - 'a';
			if (next[cur] == 0) {
				next[cur] = new Trie;
				cnt++;
			}
			next[cur]->add(c + 1);
		}
	}
	int solve(int pressCount) {
		int sum=0;
		if (flag == true) sum += pressCount;
		if (cnt == 0) return sum;

		for (int i = 0; i < 26; i++) {
			if (next[i]) {
				if (cnt+flag== 1) {
					sum+=next[i]->solve(pressCount);
					break;
				}
				else {
					sum+=next[i]->solve(pressCount + 1);
				}
			}
		}
		return sum;
	}
};

int main()
{
	fastio;
	char s[81];
	
	while (1) {
		Trie trie;
		trie.flag = true;
		int n;
		std::cin >> n;
		if (std::cin.eof() == true) break;
		for (int i = 0; i < n; i++) {
			std::cin >> s;
			trie.add(s);
		}
		std::cout<<std::fixed;
		std::cout.precision(2);
		std::cout << (double)trie.solve(0)/n<<"\n";
	}
	

	return 0;
}