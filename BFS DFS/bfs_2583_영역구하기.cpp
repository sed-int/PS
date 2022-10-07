#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

bool vis[102][102];
int board[102][102];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int m, n, k, cnt;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	while (k--){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				board[i][j] = 1;
	}

	vector<int> area;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (board[i][j] == 1 || vis[i][j]) continue;
			cnt++;
			queue<pair<int, int>> Q;
			Q.push({i, j});
			vis[i][j] = true;
			int width = 1;
			while (!Q.empty()){
				auto cur = Q.front(); Q.pop();
				for (int k = 0; k < 4; k++){
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (board[nx][ny] || vis[nx][ny]) continue;
					vis[nx][ny] = true;
					Q.push({nx, ny});
					width++;
				}
			}
			area.push_back(width);
		}
	}

	sort(area.begin(), area.end());
	cout << cnt << '\n';
	for (auto i : area)
		cout << i << " ";
}