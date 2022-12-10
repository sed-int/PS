#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1002];
long d[1002];
int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        d[i] = a[i];
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (a[j] < a[i] && d[i] < d[j] + a[i])
                d[i] = d[j] + a[i];
        // int j = i - 1;
        // while (a[j] >= a[i])
        //     j--;
    }
    cout << *max_element(d+1, d+n+1);
}

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1002];
long d[1002];
int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        d[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                d[i] = max(d[j], d[i]);
        }
        d[i] += a[i];
        cout << d[i] << ' ';
    }
    cout << *max_element(d + 1, d + n + 1);
}