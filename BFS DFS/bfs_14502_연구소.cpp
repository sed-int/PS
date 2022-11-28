#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
int board[10][10];
int virus[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, mx;
queue<pair<int, int>> Q;
queue<pair<int, int>> VQ;

bool OOB(int x, int y){
	return x < 0 || y < 0 || x >= n || y >= m;
}

void bfs(){
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			virus[i][j] = board[i][j];
			if (board[i][j] == 2)
				Q.push({i, j});
		}
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (virus[nx][ny]) continue;
			virus[nx][ny] = 2;
			Q.push({nx, ny});
		}
	}
	int t = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			t += (virus[i][j] == 0);
		}
	}
	mx = max(t, mx);
}
void rec(int k){
	if (k == 3){	
		bfs();

		return;
	}
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (board[i][j] == 0){
			board[i][j] = 1;
			rec(k + 1);
			board[i][j] = 0;
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	rec(0);
	cout << mx;	
}