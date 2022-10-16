#include<iostream>
#include<cstdlib>
using namespace std;

int n, cnt;
int arr[16];

void solve(int k){
	if (k == n){
		cnt++;
		return;
	}
	for(int i = 0; i < n; i++){
		int j = 0;
		while (j < k && i != arr[j] && abs(arr[j] - i) != k - j)
			j++;
		if (j == k){
			arr[j] = i;
			solve(k + 1);
		}
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	solve(0);
	cout << cnt;
}