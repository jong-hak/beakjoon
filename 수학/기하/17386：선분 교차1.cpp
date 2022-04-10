#include<iostream>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))


int ccw(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) {
	int n = a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);
	if (n > 0) return 1;
	else if (n < 0) return -1;
	return 0;
}

int main()
{
	fastio;
	std::pair<int, int> a, b, c,d;
	std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
	if (ccw(c, d, a) == 0 && ccw(c, d, b) == 0) {
		if ((c.first - a.first) * (d.first - a.first) <= 0 || (c.first - b.first) * (d.first - b.first) <= 0)
			std::cout << 1;
		else
			std::cout << 0;
	}
	else if (ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0)	
		std::cout << 1;
	else
		std::cout << 0;
	
	
}