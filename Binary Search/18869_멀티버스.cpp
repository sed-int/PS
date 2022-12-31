#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][10005];
void order(int x){
    vector<int> v;
    for(int i = 0; i < n; i++)
        v.push_back(a[x][i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        a[x][i] = lower_bound(v.begin(), v.end(), a[x][i]) - v.begin();
}

bool arr_compare(int x, int y){
    for (int i = 0; i < n; i++)
        if(a[x][i] != a[y][i]) return false;
    return true;
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
        order(i);
    }
    int cnt = 0;
    for(int i = 0; i < m-1; i++)
        for(int j = i+1; j < m; j++)
            if(arr_compare(i, j)) cnt++;

    cout << cnt;
}