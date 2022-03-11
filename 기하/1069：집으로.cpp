#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
double X, Y, D, T;

double min;
double solve(double remain) {

	if (remain > 2 * D) {
		return solve(remain - D)+T;
	}
	return std::min(std::min(remain, T + abs(remain - D)),  2 * T);
}

int main()
{
	fastio;
	
	std::cin >> X >> Y >> D >> T;
	std::cout << std::fixed;
	std::cout.precision(15);
	if (D <= T) {
		std::cout << sqrt(X * X + Y * Y);
	}
	else {
		std::cout << solve(sqrt(X * X + Y * Y));
	}
}