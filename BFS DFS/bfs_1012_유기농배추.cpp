#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int vis[52][52];
int board[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int> > Q;
int n, m, k;

void bfs(int x, int y){
	vis[x][y] = 1;
	Q.push(x, y);
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;			
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; i < m; j++){
			if (vis[i][j] || board[i][j] == 0) continue;
			bfs(i, j);
			ans++;
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < n; i++){
		fill(board[i], board[i]+m, 0);
		fill(vis[i], vis[i]+m, false);
	}
}