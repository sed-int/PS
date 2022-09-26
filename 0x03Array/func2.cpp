#include <bits/stdc++.h>
using namespace std;

int	func2(int arr[], int N)
{
	int occur[101]= {};

	for (int i = 0; i < N; i++)
	{
		if (occur[100 - arr[i]]) return (1);
		occur[arr[i]] = 1;
	}
	return (0);
}

int main(void)
{
	int a[3] = {1, 52, 48};
	int b[2] = {50, 42};
	int c[4] = {4, 13, 63, 87};

	cout << func2(a, 3) << '\n';
	cout << func2(b, 2) << '\n';
	cout << func2(c, 4) << '\n';
}