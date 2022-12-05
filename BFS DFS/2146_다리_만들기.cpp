#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[102][102];
bool vis[102][102];
int dist[102][102];
int n, cnt;

int area(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
        }
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            cnt++;
            vis[i][j] = 
        }
    }
}