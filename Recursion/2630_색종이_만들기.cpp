#include <iostream>
using namespace std;

#define MAX 128
int Map[MAX][MAX];
int CntOne, CntZero;

void solve(int n, int x, int y){

	bool OnlyOne, OnlyZero;
	OnlyOne = OnlyZero = true;
	for (int i = x; i < x + n; i++){
		for (int j = y; j < y + n; j++){
			if (Map[i][j] == 1) OnlyZero = false;
			if (Map[i][j] == 0) OnlyOne = false;
		}
	}
	if (OnlyZero){
		CntZero++;
		return;
	}
	if (OnlyOne){
		CntOne++;
		return;
	}
	solve(n/2, x, y);
	solve(n/2, x, y + n/2);
	solve(n/2, x + n/2, y);
	solve(n/2, x + n/2, y + n/2);
}
int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];
	solve(n, 0, 0);
	cout << CntZero << '\n' << CntOne;
}