#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

struct Trie {
	bool flag;
	std::map<std::string, Trie*> next;

	void add(std::string* words) {
		if (words->empty()) {
			flag = true;
			return;
		}
		if (next.find(*words) == next.end()) {
			next[*words] = new Trie();
		}
		next[*words]->add(words + 1);
	}
};
void dfs(Trie& trie, int d) {
	for (auto& m : trie.next) {
		for (int i = 0; i < d; i++)
			std::cout <<"--";
		std::cout << m.first<<"\n";
		dfs(*(m.second),d+1);
	}
}
int n;
Trie T;
std::string flo[16];

int main()
{
	fastio;
	int t;
	std::cin >> n;
	while (n--) {	
		std::cin >> t;
		for (int i = 0; i < t; i++) {
			std::cin >> flo[i];
		}
		flo[t].clear();
		T.add(flo);
	}
	dfs(T,0);

	return 0;
}