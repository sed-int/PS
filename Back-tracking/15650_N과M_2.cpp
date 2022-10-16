#include<iostream>
using namespace std;

int		n, m;
int		arr[50];
bool	used[50];

void solve(int k) {
	if (k == m){
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << "\n";
	}
	for (int i = 1; i <= n; i++){
		if (!used[i]){
			if (k > 0 && i < arr[k - 1]) continue;
			arr[k] = i;
			used[i] = 1;
			solve(k + 1);
			used[i] = 0;
		}

	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	solve(0);
}