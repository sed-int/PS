#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int T, n, x1, y1, x2, y2; 
int dist[302][302];
int dx[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
int dy[8] = {-1, -2, 1, 2, 2, 1, -2, -1};
queue<pair<int, int>> Q;
int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 0; i < n; i++) fill(dist[i], dist[i]+n, -1);
		cin >> x1 >> y1;
		dist[x1][y1] = 0;
		Q.push({x1, y1});
		cin >> x2 >> y2;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			for (int i = 0; i < 8; i++){
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({nx, ny});
			}
		}
		cout << dist[x2][y2] << '\n';
	}
}