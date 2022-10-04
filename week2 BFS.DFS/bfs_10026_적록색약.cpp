#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

string board[102];
int vis[102][102];
int dx[4] = {-1,0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int i, int j){
	queue<pair<int, int>> Q;
	Q.push({i, j});
	vis[i][j] = 1;
	while (!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int k = 0; k < 4; k++){
			int nx = cur.X + dx[k];
			int ny = cur.Y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] != board[i][j] || vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
}

int area(){
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (vis[i][j] == false){
				cnt++;
				bfs(i, j);
			}
		}
	}
	return cnt;
}

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];

	int not_cb, cb;

	not_cb = area();

	for (int i = 0; i < n; i++)
		fill (vis[i], vis[i]+n, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 'G') board[i][j] = 'R';

	cb = area();

	cout << not_cb << " " << cb;
}