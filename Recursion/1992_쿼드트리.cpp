#include <iostream>
using namespace std;

string Map[65];
void solve(int n, int x, int y){

	bool OnlyOne, OnlyZero;
	OnlyOne = OnlyZero = true;
	for (int i = x; i < x + n; i++){
		for (int j = y; j < y + n; j++){
			if (Map[i][j] == '1') OnlyZero = false;
			if (Map[i][j] == '0') OnlyOne = false;
		}
	}

	if (OnlyZero == true){
		cout << 0;
		return;
	}
	if (OnlyOne == true){
		cout << 1;
		return;
	}

	cout << '(';
	solve(n/2, x, y);
	solve(n/2, x, y + n/2);
	solve(n/2, x + n/2, y);
	solve(n/2, x + n/2, y + n/2);
	cout << ')';
}

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> Map[i];
	solve(n, 0, 0);
}