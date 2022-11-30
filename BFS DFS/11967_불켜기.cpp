#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> V[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        int x, y, a, b;
        V[x][y].push_back({a, b});
    }
    for (int dir = 0; dir < 4; dir++){
        
    }
}