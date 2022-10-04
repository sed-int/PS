#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++){
		fill(dist1[i], dist1[i]+m, -1);
		fill(dist2[i], dist2[i]+m, -1);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (board[i][j] == 'F'){
				Q1.push({i, j});
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J'){
				Q2.push({i,j});
				dist2[i][j] = 0;
			}
		}
	}

	while(!Q1.empty()){
		auto curr = Q1.front(); Q1.pop();
		for (int i = 0; i < 4; i++){
			int nx = dx[i] + curr.X;
			int ny = dy[i] + curr.Y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[curr.X][curr.Y] + 1;
			Q1.push({nx, ny});
			}
		}

	while(!Q2.empty()){
		auto curr = Q2.front(); Q2.pop();
		for (int i = 0; i < 4; i++){
			int nx = dx[i] + curr.X;
			int ny = dy[i] + curr.Y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << dist2[curr.X][curr.Y] + 1;
				return (0);
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[curr.X][curr.Y] + 1) continue;
			dist2[nx][ny] = dist2[curr.X][curr.Y] + 1;
			Q2.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
}