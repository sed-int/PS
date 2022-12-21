#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cache[1002], price[1002];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> price[i];


    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cache[i] = max(cache[i], cache[i-j] + price[j]);
    
    cout << cache[n];
}