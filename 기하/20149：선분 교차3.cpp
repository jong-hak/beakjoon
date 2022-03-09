#include<iostream>
#include<algorithm>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define EPSILON 0.00000000000001
#define p std::pair<double, double>

int ccw(p a, p b, p c) {
	double n = a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);
	if (n > 0) return 1;
	else if (n < 0) return -1;
	return 0;
}
bool isIntersect(p a, p b, p c, p d) {
	int d1 = ccw(a, b, c);
	int d2 = ccw(a, b, d);
	int d3 = ccw(c, d, a);
	int d4 = ccw(c, d, b);
	if (d1 * d2 == 0 && d3 * d4 == 0) {
		if (d<a || c>b)
			return 0;
		return 1;
	}
	else if (d1 * d2 <= 0 && d3 * d4 <= 0)
		return 1;
	return 0;
}

int main()
{
	fastio;
	p a, b, c,d;
	std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
	if (a > b) std::swap(a, b);
	if (c > d) std::swap(c, d);
	if (isIntersect(a, b, c, d)) {

		double k = (a.first - b.first) * (c.second - d.second) - (a.second - b.second) * (c.first - d.first);
		if (abs(k) < EPSILON) {
			if (a == d)
				std::cout << 1 << "\n" << a.first << " " << a.second;
			else if (b == c)
				std::cout << 1 << "\n" << b.first << " " << b.second;
			else
				std::cout << 1;
		}
		else {
			double x = ((a.first * b.second - a.second * b.first) * (c.first - d.first) - (a.first - b.first) * (c.first * d.second - c.second * d.first)) / k;
			double y = ((a.first * b.second - a.second * b.first) * (c.second - d.second) - (a.second - b.second) * (c.first * d.second - c.second * d.first)) / k;
			std::cout << std::fixed;
			std::cout.precision(10);
			std::cout << 1 << "\n" << x << " " << y;
		}
			
	}
	else {
		std::cout << 0;
	}
}