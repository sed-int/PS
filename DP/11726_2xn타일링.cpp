#include <iostream>
#include <algorithm>
using namespace std;

int const Mod = 10007;
int n, cache[1002];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    cache[1] = 1;
    cache[2] = 2;
    for(int i = 3; i <= n; i++)
        cache[i] = (cache[i-2]+cache[i-1])%Mod;
    cout << cache[n];
}