#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, v , arr[201] = {};

	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		arr[tmp+100]++;
	}
	cin >> v;
	cout << arr[v+100];
}