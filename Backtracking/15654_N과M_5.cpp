#include<iostream>
#include<algorithm>
using namespace std;

int		n, m;
int		input[10];
int		arr[10];
bool	used[10];

void	solve(int k){
	if (k == m){
		for (int i = 0; i < m; i++) cout << input[arr[i]] << ' ';
		cout << '\n';
	}
	for (int i = 0; i < n; i++){
		if(!used[i]){
			arr[k] = i;
			used[i] = true;
			solve(k+1);
			used[i] = false;
		}
	}
}
int	main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> input[i];
	sort(input, input+n);
	solve(0);
}