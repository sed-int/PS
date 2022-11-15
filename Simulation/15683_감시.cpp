#include<iostream>
using namespace std;

int Map[10][10];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> Map[i][j];
		}
	}	

}
