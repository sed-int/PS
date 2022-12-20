#include <iostream>
using namespace std;

int c, n, m;
bool areFriends[12][12];

int countPairs(bool taken[10]){
    int firstFree = -1;
    for (int i = 0; i < n; i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) return 1;
    int ret = 0;
    for (int pairWith = firstFree+1; pairWith < n; ++pairWith){
        if (!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairs(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}
int main(void){
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    cin >> c;
    while(c--){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            fill(areFriends[i], areFriends[i]+12, false);
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
        }
        bool taken[10] = {false};
        cout << countPairs(taken) << "\n";
    }
}