#include<iostream>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define ll long long

int ccw(std::pair<ll, ll> a, std::pair<ll, ll> b, std::pair<ll, ll> c) {
	ll n = a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);
	if (n > 0) return 1;
	else if (n < 0) return -1;
	return 0;
}

int main()
{
	fastio;
	std::pair<ll, ll> a, b, c,d;
	std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
	ll d1 = ccw(a, b, c);
	ll d2 = ccw(a, b, d);
	ll d3 = ccw(c, d, a);
	ll d4 = ccw(c, d, b);
	if (d1 *  d2 == 0 && d3 * d4 == 0)	{
		if (a > b) std::swap(a, b);
		if (c > d) std::swap(c, d);
		if (d<a || c>b)
			std::cout << 0;
		else
			std::cout << 1;
	}
	else if (d1 * d2 <= 0 && d3 * d4 <= 0)
		std::cout << 1;
	else
		std::cout << 0;
}