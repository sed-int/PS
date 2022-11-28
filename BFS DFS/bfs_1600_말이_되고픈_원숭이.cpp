#include <iostream>
#include <queue>
using namespace std;

int board[202][202];
bool vis[202][202][32];
int hdx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hdy[8] = {-1, 1, -2, 2, -2, 2, 1, -1};
int mdx[4] = {-1, 0, 1, 0};
int mdy[4] = {0, 1, 0, -1};
int k, w, h;
int main(void){
	queue<tuple<int, int, int> > Q;
	cin >> k >> w >> h;	
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			cin >> board[i][j];
	while(!Q.empty()){
		int x, y, z;
		tie(x, y, z) = Q.front(); Q.pop();
		if (z < k) {
			for (int dir = 0; dir < 8; dir++){
			int nx = x + hdx[dir];
			int ny = y + hdy[dir];
			if (nx < 0 || ny > 0 || w <= nx || h <= ny) continue;
			if (board[nx][ny]) continue;
			if (vix[nx][ny] || board[nx][ny] != 1) continue;
			Q.push({nx, ny, z + 1});
			}
		}
		for (int dir = 0; dir < 4; dir++){
			int nx = x + mdx[dir];
			int ny = y + mdy[dir];
			if(nx < 0 || ny < 0 || )
		}
	}
}