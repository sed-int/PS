#include <iostream>
#include <stack>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int n;
    long long ans = 0;

    cin >> n;
    while (n--)
    {
        long long h;
        cin >> h;
        while (!S.empty() && S.top() <= h)
            S.pop();
		ans += S.size();
        S.push(h);
    }
    cout << ans;
}