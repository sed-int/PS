#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k, a[10005];
bool solve(ll x){
    int cnt = 0;
    for(int i = 0; i < k; i++){
        if (a[i] >= x) cnt += a[i] / x;
    }
    return cnt >= n;
}
int main(void){
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    
    ll st = 0;
    ll en = 0x7fffffff;
    while(st < en){
        int mid = (st + en + 1)/2;
        if(solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
}