#include<iostream>
#include<algorithm>
#include<string>
#include<memory.h>
#include<vector>
#include<queue>
#include<tuple>
#include<math.h>
#define fastio (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL))

int move[8][2] = { {-1,0},{-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1} };

std::pair<int,int> space[4][4];	//-1 »ó¾î, 0 ºó°ø°£
std::pair<int, int> fish[17];
void copy(std::pair<int, int> to[][4], std::pair<int, int> from[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			to[i][k] = from[i][k];
		}
	}
}
void simulate(){
	
	std::fill(fish, fish + 17, std::make_pair(-1, -1));
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if(space[i][k].first == -1) continue;
			fish[space[i][k].first].first = i;  
			fish[space[i][k].first].second = k;
		}
	}
	int r,c,nr,nc;
	for (int i = 1; i <= 16; i++) {
	
		if (fish[i].first == -1) continue;
		r = fish[i].first; c = fish[i].second;
		std::pair<int, int>& cur = space[r][c];
		
		for (int k = 0; k < 8; k++) {
			nr = r + move[cur.second][0]; nc = c + move[cur.second][1];
			if ( nr>=0 && nc>=0 && nr<4 && nc<4 && space[nr][nc].first != -1) {
				std::swap(fish[space[nr][nc].first], fish[space[r][c].first]);
				std::swap(space[nr][nc], space[r][c]);
				break;
			}
			cur.second = ++cur.second % 8;
		}
	}
}
int solve(int r, int c, int dir) {
	
	simulate();
	std::pair<int, int> tmp[4][4];
	space[r][c].first = 0;
	copy(tmp, space);
	int max = 0;
	int nr=r, nc=c;
	int n,d;
	while (1) {
		nr += move[dir][0]; nc += move[dir][1];
		if (nr > 3 || nc > 3 || nr < 0 || nc < 0 ) break;
		if (space[nr][nc].first < 1) continue;

		n = space[nr][nc].first; d = space[nr][nc].second;
		space[nr][nc].first = -1;
		max = std::max(max, solve(nr, nc, d)+n) ;
		copy(space, tmp);
	}

	return max;
}

int main()
{
	fastio;
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			std::cin >> a >> b;
			space[i][k].first = a, space[i][k].second = b-1;
		}
	}
	int f = space[0][0].first, d = space[0][0].second;
	space[0][0].first = -1;
	std::cout << f + solve(0,0,d);
}