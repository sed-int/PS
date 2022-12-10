#include <iostream>
#include <algorithm>
using namespace std;

int n, m, vip[42], d[42];

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> vip[i];
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++)
        d[i] = d[i-2] + d[i-1];
    int ans = 1;
    int start = 0;
    for (int i = 0; i < m; i++)
    {
        int end = vip[i];
        ans *= d[end - start - 1];
        start = end;
    }
        ans *= d[n - start];
    cout << ans;
}