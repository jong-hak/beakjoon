#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<unordered_map>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long

// 해시 맵을 이용한 풀이, 해시 맵의 오버헤드 때문에 시간이 많이 걸린 것 같음
/*
int N,S;
int arr[40];
std::unordered_map<int, ll> left;
std::unordered_map<int, ll> right;

void get_left(int d, ll sum) {
	if (d >= N / 2) return;
	get_left(d + 1,sum);
	ll s = sum + arr[d];
	left[s]++;
	get_left(d + 1, s);
}
void get_right(int d, ll sum) {
	if (d >= N) return;
	get_right(d + 1, sum);
	ll s = sum + arr[d];
	 right[s]++;
	get_right(d + 1, s);
}

int main() {
	fastio;
	std::cin >> N>>S;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	get_left(0, 0); get_right(N / 2, 0);
	ll answer = 0;
	if (left.find(S) != left.end()) answer += left[S];
	if (right.find(S) != right.end()) answer += right[S];
	for (auto& l : left) {
		answer += l.second * right[S - l.first];
	}
	std::cout << answer;

}
*/

int N, S, mid=2000000;
int arr[40];
int left[4000001];
ll answer=0;

void get_left(int d, int sum) {
	if (d < N / 2) {
		get_left(d + 1, sum);
		get_left(d + 1, sum + arr[d]);
		
	}
	else {
		left[sum + mid]++;
	}
}
void get_right(int d, int sum) {
	if (d < N) {
		get_right(d + 1, sum);
		get_right(d + 1, sum + arr[d]);

	}
	else if(S - sum >=-2000000 && S - sum<=2000000) {
		answer += left[S-sum+mid];
	}
}

int main() {
	fastio;
	std::cin >> N >> S;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	get_left(0, 0);
	get_right(N / 2, 0);

	std::cout << (S ? answer : answer-1);

}