#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    cin >> m;
    while(m--){
        int t;
        cin >> t;
        cout << binary_search(a, a+n, t) << ' ';
    } 
}