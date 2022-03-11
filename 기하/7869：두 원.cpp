#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))
#define Pi 3.14159265359

int main()
{
	fastio;
	double x1, y1, r1, x2, y2, r2;
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2>> r2;
	double A, B;
	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d >= r1 + r2) {
		double a = 0;
		std::cout << std::fixed;
		std::cout.precision(3);
		std::cout << a;
	}
	else if (d + r1 <= r2){
		std::cout << r1 * r1 * Pi;
	}
	else if (d + r2 <= r1) {
		std::cout << r2 * r2 * Pi;
	}
	else {
		A = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
		B = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
		std::cout << std::fixed;
		std::cout.precision(3);
		std::cout << r2 * r2 * B + r1 * r1 * A - r1 * sin(A) * d;
	}
}