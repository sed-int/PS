#include<iostream>
#include<algorithm>
using namespace std;

int k[100002];
int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> k[i];
	sort(k, k+n);
	for (int i = 0; i < n; i++)
		k[i] = k[i] * (n - i);
	sort(k, k+n);
	cout << k[n - 1];
}