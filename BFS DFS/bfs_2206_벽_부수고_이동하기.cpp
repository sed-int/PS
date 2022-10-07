#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int dist[1002][1002][2];
string board[1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int bfs(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	dist[0][0][0] = dist[0][0][1] = 1;
	queue<tuple<int, int, int>> Q;
	Q.push({0, 0, 0});
	while (!Q.empty()){
		int x, y, w;
		tie(x, y, w) = Q.front();
		if (x == n-1 && y == m-1) return dist[x][y][w];
		Q.pop();
		for (int dir = 0; dir < 4; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][w] == -1){
				dist[nx][ny][w] = dist[x][y][w] + 1;
				Q.push({nx, ny, w});
			}
			if (w == 0 && board[nx][ny] == '1' && dist[nx][ny][1] == -1){
				dist[nx][ny][1] = dist[x][y][w] + 1;
				Q.push({nx, ny, 1});
			}
		}
	}
	return (-1);
}

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	cout << bfs();
	return (0);
}