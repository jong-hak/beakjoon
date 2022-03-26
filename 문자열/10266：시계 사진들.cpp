#include<iostream>
#include<algorithm>
#include<string>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int n;
int arr[2][200000];

int pi[200000];

void getPi() {
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && arr[0][i] != arr[0][j])  {
			j = pi[j - 1];
		}
		j += arr[0][i] && arr[0][j];
		pi[i] = j;
	}
}
void solve() {
	getPi();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && arr[0][j] != arr[1][i]) {
			j = pi[j - 1];
		}
		if (arr[0][j] == arr[1][i]) j++;
	}

	for (int i = j; i < n; i++) {
		if (arr[0][i] != arr[1][i - j]) {
			std::cout << "impossible";
			return;
		}
	}
	std::cout << "possible";
}


int main()
{
	fastio;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[0][i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> arr[1][i];
	}
	std::sort(arr[0], arr[0] + n);
	std::sort(arr[1], arr[1] + n);
	int tmp = 360000 + arr[0][0] - arr[0][n - 1];
	for (int i = 0; i < n-1; i++) {
		arr[0][i] = arr[0][i + 1] - arr[0][i];
	}
	arr[0][n - 1] = tmp;
	tmp = 360000 + arr[1][0] - arr[1][n - 1];
	for (int i = 0; i < n-1; i++) {
		arr[1][i] = arr[1][i + 1] - arr[1][i];
	}
	arr[1][n - 1] = tmp;

	solve();

	return 0;
}