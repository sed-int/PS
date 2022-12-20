#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100002], m;

int binarySearch(int target){
    int start = 0, end = n-1;
    while (start <= end){
        int mid = (start + end)/2;
        if (a[mid] < target)
            start = mid + 1;
        else if (a[mid] > target)
            end = mid - 1;
        else return 1;
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    cin >> m;
    while(m--){
        int t;
        cin >> t;
        cout << binarySearch(t) << '\n';
    }
}