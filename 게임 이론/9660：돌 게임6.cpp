#include<iostream>
#include<algorithm>
#include<memory.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

bool win[7] = { 0,1,0,1,1,1,1 };

int main(){
	fastio;
	long long N;
	std::cin >> N;
	if (win[N % 7]) std::cout << "SK";
	else std::cout << "CY";
	return 0;
}