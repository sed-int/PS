#include <iostream>
#include <queue>
#include <string>
using namespace std;

const string Stair = "use the stairs";
int dist[1000002];
int F, S, G, U, D;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;
    fill(dist, dist+F+1, -1);
    queue<int> Q;
    dist[s] = 0;
    Q.push(0);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (auto nxt : {cur + U, cur - D}){
            if  (nxt <= 0 || nxt > F || dist[nxt] == -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    if (dist[g] == -1) cout << Stair;
    else cout << dist[g];
}