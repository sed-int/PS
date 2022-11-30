#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char Building[32][32][32];
int dist[32][32][32];
int L, R, C;
int ex, ey, ez;
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {-1, 0, 1, 0, 0, 0};
queue<tuple<int, int, int>> Q;

bool OOB(int a, int b, int c){
    return a < 0 || b < 0 || c < 0 || a >= L || b >= R || c >= C;
}

void init(){
    for (int i = 0; i < L; i++){
        for (int j = 0; j < R; j++){
            for (int k = 0; k < C; k++){
                Building[i][j][k] = ' ';
                dist[i][j][k] = -1;                
            }
        }
    }

    for (int i = 0; i < L; i++){
        for (int j = 0; j < R; j++){
            for (int k = 0; k < C; k++){
                cin >> Building[i][j][k];
                if (Building[i][j][k] == 'S') {
                    Q.push({i, j, k});
                    dist[i][j][k] = 0;
                }
                if (Building[i][j][k] == 'E') {
                    tie(ex, ey, ez) = {i, j, k};                  
                }
            }
        }
    }
}

int BFS(){
    while(!Q.empty()){
        int x, y, z;
        tie(x, y, z) = Q.front(); Q.pop();
        for (int dir = 0; dir < 6; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (OOB(nx, ny, nz)) continue;
            if (dist[nx][ny][nz] != -1) continue;
            if (Building[nx][ny][nz] == '#') continue;
            Q.push({nx, ny, nz});
            dist[nx][ny][nz] = dist[x][y][z] + 1;
        }
    }
    return dist[ex][ey][ez];
}

int main(void){
    freopen("input.txt", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;
        init ();
        int res = BFS();    
        if (res != -1)
            cout << "Escaped in " << res <<" minute(s)." << "\n";
        else
            cout << "Trapped!" << "\n";
    }
}