#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[100002], cache[100002];
int main(void){
    freopen("input.txt", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cache[i] = a[i] + cache[i-1];
    while(m--){
        int st, en;
        cin >> st >> en;
        cout << cache[en] - cache[st-1] << "\n";
    }
}