#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[500002];
int lowerIdx(int target, int len){
    int start = 0;
    int end = len;
    while(start < end){
        int mid = (start + end) / 2;
        if (a[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    return start; 
}

int upperIdx(int target, int len){
    int start = 0;
    int end = len;
    while (start < end){
        int mid = (start + end) / 2;
        if (a[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    sort(a, a+n);
    while (m--){
        int t;
        cin >> t;
        cout << upperIdx(t, n) - lowerIdx(t, n) << " ";
    }
}
