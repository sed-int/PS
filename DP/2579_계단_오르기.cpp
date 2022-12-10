#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[305][3];
int a[305];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if(n == 1){
        cout << a[1];
        return 0;
    }
    d[1][1] = a[1];
    d[1][2] = 0;
    d[2][1] = a[2];
    d[2][2] = a[1] + a[2];
    for (int i = 3; i <= n; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
        d[i][2] = d[i-1][1] + a[i];
    }
    cout << max(d[n][1], d[n][2]);
}