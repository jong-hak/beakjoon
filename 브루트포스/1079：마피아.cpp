#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int N, me;
int guilty[16];
int R[16][16];
int answer;
bool flag = false;

void solve(int death, int d, int n) {
	if (flag) return;
	if (n % 2) {
		int id = -1, pt=-1;
		for (int i = 0; i < N; i++) {
			if (death & (1 << i)) continue;
			if (guilty[i] > pt) {
				pt = guilty[i];
				id = i;
			}
		}
		if (id == me || n == 3) {
			if (n == 3 && id!=me) d++,flag = true;
			answer = std::max(answer, d);
			return;
		}
		solve(death | (1 << id), d, n - 1);

	}
	
	else {
		for (int i = 0,b = 1; i < N; i++, b<<=1) {
			if ((b & death) || i == me) continue;
			int tmp[16];
			memcpy(tmp, guilty, sizeof(guilty));
			for (int k = 0; k < N; k++) {
				guilty[k] += R[i][k];
			}
			solve(death | b, d + 1, n - 1);
			memcpy(guilty,tmp, sizeof(guilty));
		
		}
	}
}

int main()
{
	fastio;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> guilty[i];
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			std::cin >> R[i][k];
		}
	}
	std::cin >> me;
	solve(0, 0, N);
	std::cout << answer;

}