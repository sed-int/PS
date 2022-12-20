#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, p;
int cnt[10];
int player[10];
int castle[10];
char board[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = (0, -1, 0, 1);
queue<tuple<int, int, int>> q[10];

bool OOB(int x, int y){
    return x < 0 || y < 0 || x >= n || y >= m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> player[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            int k = board[i][j] - '0';
            if (k >= 0 && k <= 9)
                q[k].push({i, j, 0});                
        }
    }

    while(1){
        bool isOver = false;
        for (int i = 1; i <= p; i++){
            queue<tuple<int, int, int>> nq;
            if(t >= player[i]){
                nq.push({x, y, 0});
                continue;
            }
            while(!Q[i].empty()){
                int x, y, t;
                tie(x, y, t) = q[i].front(); q[i].pop();
                if (t == cnt[i]){

                }
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (OOB(nx, ny)) continue;
                    if (board[nx][ny] != '.') continue;
                    q[i].push({nx, ny, t+1});
                }
            }
        }
    }    
}