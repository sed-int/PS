#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[10]= {};
	int min = 1;
	int N;
	cin >> N;

	while(N)
	{
		arr[N%10]++;
		N /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9) continue;
		min = max(min, arr[i])
	}
	min = max(min, (a[6]+a[9]+1)/2);
	cout << min;
}