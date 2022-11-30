#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char board[102][102];
string key;
bool vis[102][102];
int T, h, w;

bool OOB(int x, int y){
    return x < 0 || y < 0 || x >= h || y >= w;
}
int main(void){
    cin >> T;
    while(T--){
        queue<pair<int, int>> Q;
        queue<pair<int, int>> D[26];
        cin >> h >> w;
        for (int i = 0; i < h; i++){
            fill(vis[i], vis[i]+w+1, 0);
            fill(board[i], board[i]+w+2, 0);
        }
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> board[i][j];
        cin >> key;
        bool keybox[26] = {false};
        for (auto s : key) keybox[s - 'a'] = true;
        int cnt = 0;
        Q.push({0. 0});
        vis[0][0] = true;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                if (OOB(nx, ny)) continue;
                if (board[nx][ny] == '*' || vis[nx][ny]) continue;
                
                // 열쇠
                if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
                    char c = board[nx][ny];
                    keybox[c - 'a'] = true;
                    while(!D[c - 'a'].empty()){
                        auto door = D[c - 'a'].front(); D[c - 'a'].pop();
                        Q.push({door.X, door.Y});
                    }
                }
                //문
                else if (board[nx][ny] >= 'A' && borad[nx][ny] <= 'Z'){
                    char c = board[nx][ny];
                    if (keybox[c - 'A']){
                        board[nx][ny] = '.';
                        D[c - 'A'].push({nx, ny});
                    }
                }
                else if (board[nx][ny] == '$') cnt++;
                Q.push({nx, ny});
            }
        }
        cout << cnt << "\n";
    }
}