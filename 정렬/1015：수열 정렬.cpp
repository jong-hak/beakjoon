#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<math.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N;
int A[50];
int answer[50];

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		int rank = 0;
		for (int k = 0; k < N; k++) {
			if (A[i] > A[k] || (A[i] ==A[k] && i>k)) rank++;
		}
		answer[i] = rank;
	}
	for (int i = 0; i < N; i++)
		std::cout << answer[i] << " ";
}