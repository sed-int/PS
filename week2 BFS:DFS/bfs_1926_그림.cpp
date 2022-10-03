#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int board [502][502];
bool vis[502][502];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int main(void){
	freopen("input.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int mx = 0, num = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			// (i, j)를 이미 방문했거나, (i, j)가 그림의 일부가 아닌 경우 건너뛴다.
			if (board[i][j] == 0 || vis[i][j]) continue;
			// 그 외의 경우에는 그림의 개수를 추가한다.
			num++;
			// (i, j)부터 bfs 시작할 준비.
			queue<pair<int, int>> Q;
			vis[i][j] = true;
			Q.push({i, j});
			// 그림의 넓이
			int area = 0;
			while (!Q.empty()){
				pair<int, int> curr = Q.front(); Q.pop();
				// 큐에서 원소를 뺄 경우, 그림의 넓이가 증가.
				area++;
				for(int k = 0; k < 4; k++) {
					int nx = curr.X + dx[k];
					int ny = curr.Y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis [nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = true; // 방문 기록.
					Q.push({nx, ny}); 
				}
			}
			// 하나의 그림을 다 탐색하면 넓이를 비교해 최댓값을 결정한다.
			mx = max(mx, area);
		}
	}
	cout << num << "\n" << mx;
}