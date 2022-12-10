#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100002], d[100002];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    d[1] = a[1];
    for (int i = 2; i <= n; i++){
        d[i] = max(a[i], d[i-1]+a[i]);
    }
    cout << *max_element(d+1, d+n+1);
}