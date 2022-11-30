#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second
string board[27];
bool vis[27][27];
vector<int> ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n;

bool OOB(int x, int y){
    return x < 0 || y < 0 || x >= n || y >= n;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
    if(board[i][j] == '0' || vis[i][j]) continue;
    queue<pair<int, int>> Q;
    Q.push({i, j});
    vis[i][j] = true;
    int cnt = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] == '0') continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
            cnt++;
        }
    }
    ans.push_back(cnt);
}
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << "\n";
}