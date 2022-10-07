#include <iostrema>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dist1[1002][1002];
int dist2[1002][1002];
string board[1002];
int n, m;

void bfs(){
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = cur.X +dx[i];
			int ny = cur.Y +dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0 || dist)
		}
	}
}
int main(void){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
			cin >> string[i];
	fill(dist1, dist1+m, -1);
	fill(dist2, dist2+m, -1);
	dist1[0][0] = 0;
	dist2[0][0] = 0;
	queue<pair<int, int> > Q;
	Q.push({0, 0});
	while (Q)
}