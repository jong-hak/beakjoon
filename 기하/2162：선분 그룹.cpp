#include<iostream>
#include<algorithm>
#include<string.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define p std::pair<int, int>
#define line std::pair<p,p>

int ccw(p& a, p& b, p& c) {
	int n = a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);
	if (n > 0) return 1;
	if (n < 0) return -1;
	return 0;
}

bool isInterSect(line& q1, line& q2) {
	p a = q1.first;
	p b = q1.second;
	p c = q2.first;
	p d = q2.second;
	int d1 = ccw(a, b, c) * ccw(a, b, d);
	int d2 = ccw(c, d, a) * ccw(c, d, b);
	if (d1 == 0 && d2 == 0) {
		if (a > b) std::swap(a, b);
		if (c > d) std::swap(c, d);
		if (a > d || b < c) return 0;
		return 1;
	}
	else if (d1 <= 0 && d2 <= 0)
		return 1;
	return 0;
}

line l[3000];
int count[3000];
int parent[3000];
int n;

int find(int c) {
	if (parent[c] < 0 || parent[c] == c) return parent[c] = c;
	int y = find(parent[c]);
	parent[c] = y;
	return y;
}
void Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	count[b] += count[a];
	parent[a] = b;
}

void solve() {
	int groupCnt = n;

	for (int i = 0; i < n-1; i++) {
		for (int k = i + 1; k < n; k++) {
			if (!isInterSect(l[i], l[k])) continue;
			if (find(i) == find(k)) continue;
			Union(i, k);
			groupCnt--;
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		max = std::max(max, count[i]);
	}
	std::cout << groupCnt << "\n" << max;
}

int main()
{
	fastio;
	std::cin >> n;
	memset(parent, -1, 4 * n);
	for (int i = 0; i < n; i++) {
		std::cin >> l[i].first.first >> l[i].first.second >> l[i].second.first >> l[i].second.second;
		count[i] = 1;
	}
	solve();
}