#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
int m, n, l[1000002];
bool solve(int x){
    if(x == 0) return true;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += l[i]/x;
    return cnt >= m;
}
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i];
    sort(l, l+n);
    int st = 0;
    int en = l[n-1];
    while(st < en){
        int mid = (st + en + 1)/2;
        if(solve(mid))
            st = mid;
        else   
            en = mid - 1;
    }
    cout << st << "\n";
}