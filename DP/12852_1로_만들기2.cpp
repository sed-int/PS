#include <iostream>
#include <algorithm>
using namespace std;

int n, cache[1000002], pre[1000002];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    cache[1] = 0;
    for (int i = 2; i <= n; i++){
        cache[i] = cache[i-1] + 1;
        pre[i] = i-1;
        if (i%3 == 0 && cache[i] > cache[i/3] + 1){
            cache[i] = cache[i/3]+1;
            pre[i] = i/3;
        }
        if (i%2 == 0 && cache[i] > cache[i/2] + 1) {
            cache[i] = cache[i/2]+1;
            pre[i] = i/2;
        }
    }
    cout << cache[n] << "\n";
    int cur = n;
    while(true){
        cout << cur << " ";
        if (cur == 1) break;
        cur = pre[cur];
    }
}