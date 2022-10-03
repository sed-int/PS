#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({0, 0});
	while(!Q.empty()){
		pair<int, int> curr = Q.front();
		Q.pop();
		cout << '(' << curr.X << ", " << curr.Y << ") ";
		for (int i = 0; i < 4; i++){
			int nx = curr.X + dx[i];
			int ny = curr.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			Q.push({nx, ny});
		}
	}
}
