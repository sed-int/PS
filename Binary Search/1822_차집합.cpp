#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, a[500005], b[500005];
queue<int> q;
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if(!binary_search(b, b+m, a[i])){
            cnt++;
            q.push(a[i]);
        }
    cout << cnt << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}