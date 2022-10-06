#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int dist1[1002][1002];
int dist2[1002][1002];
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
int board[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = (1, 0, -1, 0);
int w, h;

void bfs(int x, int y){
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
		}
	}
}

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		cin >> h >> w;
		
		for (int i = 0; i < h; i++) fill(dist1[i], dist1[i]+w, -1);
		for (int i = 0; i < h; i++) fill(dist2[i], dist2[i]+w, -1);
		
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> board[i][j];
				if (board[i][j] == '*'){
					dist1[i][j] = 0;
					Q1.push({i, j});
				}
				if (board[i][j] == '@'){
					dist2[i][j] = 0;
					Q2.push({i, j});
				}
			}
		}

		while(!Q1.empty()){
			auto cur = Q1.front(); Q1.pop();
			for (int i = 0; i < 4; i++){
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
				Q1.push({nx, ny});
			}
		}

		while(!Q2.empty()){
			auto cur = Q.front(); Q.pop();
			for (int i = 0; i < 4; i++){
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w){
					cout << dist2[cur.X][cur.Y] + 1 << '\n';
					return (0);
				}
				if (dist2[nx][ny] <= dist1[nx][ny]) continue;
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				Q1.push({nx, ny});
			}
		}

		cout << "IMPOSSIBLE\n";
	}
}