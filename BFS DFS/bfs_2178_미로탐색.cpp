#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int n, m;
int dist[102][102];
string board[102];
int dx[4] = {0, 1, 0, -1};
int	dy[4] = {1, 0, -1, 0};

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) fill(dist[i], dist[i]+m, -1);

	queue<pair<int, int>> Q;
	Q.push({0, 0});
	dist[0][0] = 0;

	while(!Q.empty()){
		auto curr = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = curr.X + dx[i];
			int ny = curr.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
			dist[nx][ny] = dist[curr.X][curr.Y] + 1;
			Q.push({nx, ny});
		}
	}
	cout << dist[n-1][m-1] + 1;
}