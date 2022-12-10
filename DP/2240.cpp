#include <iostream>
#include <algorithm>
using namespace std;

int t, w, a[1005], d[1005][35];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> a[i];
    
    int cnt = 0;
    for (int i = 1; i <= t; i++){
        if (a[i] == 1) cnt++;
        d[i][0] = cnt;
    }

    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= w; j++)
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) + (a[i] == j % 2 + 1);
    cout << *max_element(d[t], d[t]+w+1);
}