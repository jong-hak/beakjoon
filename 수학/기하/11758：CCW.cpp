#include<iostream>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))



int main()
{
	fastio;
	std::pair<int, int> a, b, c;
	std::cin >> a.first >> a.second;
	std::cin >> b.first >> b.second;
	std::cin >> c.first >> c.second;
	int ccw = a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);

	if (ccw > 0) std::cout << 1;
	else if (ccw < 0) std::cout << -1;
	else std::cout << 0;
	
}