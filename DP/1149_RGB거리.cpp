#include <iostream>
#include <algorithm>
using namespace std;

int n, cache[1002][5];
int r[1002], g[1002], b[1002];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i] >> g[i] >> b[i];
    cache[1][0] = r[1];
    cache[1][1] = g[1];
    cache[1][2] = b[1];
    for (int i = 2; i <= n; i++){
        cache[i][0] = min(cache[i-1][1], cache[i-1][2]) + r[i];
        cache[i][1] = min(cache[i-1][0], cache[i-1][2]) + g[i];
        cache[i][2] = min(cache[i-1][0], cache[i-1][1]) + b[i];
    }
    cout << *min_element(cache[n], cache[n]+3);
}