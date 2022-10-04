#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
			if (board[i][j] == 1)
				Q.push({i, j});
			if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}

	while(!Q.empty()){
		auto curr = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = curr.X + dx[i];
			int ny = curr.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[curr.X][curr.Y] + 1;
			Q.push({nx, ny});
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(dist[i][j] == -1){
				cout << -1;
				return (0);
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}