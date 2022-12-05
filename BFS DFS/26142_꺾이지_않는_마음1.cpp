#include <iostream>
#include <algorithm>
using namespace std;

int d[10005];
int h[10005];
int ans[10005];
int n;

bool cmp(int a, int b){
    return a > b;
}

void harvest(int day){
    ans[day] = ans[day - 1] + h[day];
    h[day] = 0;
}

void grow(int day){
    for (int i = 0; i < n; i++)
        h[i] += d[day];          
}

int main(void){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> d[i] >> h[i-1];
    }
    sort (h, h+n, cmp);
    ans[0] = h[0];
    h[0] = 0;
    for (int day = 1; day < n; day++){
        grow(day);
        harvest(day);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";   
}