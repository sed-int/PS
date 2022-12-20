#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1002], cache[1002];
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(cache, cache+n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) cache[i] = max(cache[i], cache[j]+1);

    cout << *max_element(cache, cache+n);
}