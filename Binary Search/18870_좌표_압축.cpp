#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[1000002];
vector<int> tmp, unq;

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tmp.push_back(a[i]);
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++){
        if (i == 0 || tmp[i-1] != tmp[i])
        unq.push_back(tmp[i]);
    }
    for (int i = 0; i < n; i++)
        cout << lower_bound(unq.begin(), unq.end(), a[i]) - unq.begin() << ' ';
}