#include <iostream>
using namespace std;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int buildings[1002] = {};
	int r[4] = {-2, -1, 1, 2};
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> buildings[i];

	for (int i = 2; i <  n-2; i++){
		int mx = 0;
		for (int j = 0; j < 4; j++){
			int cur = i + r[j];
			mx = max(buildings[cur], mx);
		}
		if (buildings[i] > mx)
		ans += buildings[i] - mx;
	}
	cout << ans;
}