#include<iostream>
#include<algorithm>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

std::string T;
std::string P;

int pi[1000000];

int result[1000000];
int cnt = 0;

void getPi() {
	int j = 0;
	for (int i = 1; i < P.length(); i++) {
		while (j > 0 && P[j] != P[i]) {
			j = pi[j-1];
		}
		j += (P[i] == P[j]);
		pi[i] = j;
	}
}

void KMP() {
	getPi();
	int j = 0;
	for (int i = 0; i < T.length(); i++) {
		while (j > 0 && P[j] != T[i]) {
			j = pi[j-1];
		}
		
		if (P[j] == T[i]) j++;
		if (j == P.length()) {
			result[cnt++] = i - P.length() + 2  ;
		}
	}
}

int main()
{
	fastio;
	std::getline(std::cin,T);
	std::getline(std::cin, P);
	KMP();
	std::cout << cnt<<"\n";
	for (int i = 0; i < cnt; i++) {
		std::cout << result[i] <<" ";
	}

	return 0;
}