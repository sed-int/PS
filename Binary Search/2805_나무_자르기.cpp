#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t[1000005];
bool solve(int h){
    long long cur = 0;
    for (int i = 0; i < n; i++){
        if(t[i] <= h) continue;
        cur += t[i] - h;
    }
    return cur >= m;
}
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int st = 0;
    int en = *max_element(t, t+n);
    while(st < en){
        int mid = (st+en+1)/2;
        if(solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
}