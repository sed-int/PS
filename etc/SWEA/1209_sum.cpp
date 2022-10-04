#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	for (int k = 0; k < 10; k++){
		int num;
		cin >> num;
		int board[102][102];
		int h[102] = {};
		int v[102] = {};
		int d = 0, mx = 0;

		for (int i = 0; i < 100; i++){
			for (int j = 0; j < 100; j++){
				cin >> board[i][j];
				h[i] += board[i][j];
				v[j] += board[i][j];
				if (i == j) d += board[i][j];
			}
			mx = max(h[i], mx);
		}
		int v_mx = *max_element(v, v+99);
		mx = max(v_mx, mx);
		mx = max(d, mx);
		cout << "#" << num << " " << mx << '\n';
	}
}