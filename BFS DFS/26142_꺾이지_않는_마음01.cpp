#include <iostream>
#include <algorithm>
using namespace std;

#define d first
#define h second
pair<int, int> dragons[10005];
int [10005];
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
    freopen("dragons.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> dragons[i].d >> dragons[i].h;
    }
    sort(dragons, dragons+n)
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            ans[i] += dragons[j].h + j * dragons[j].d;
}