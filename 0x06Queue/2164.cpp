#include <iostream>
#include <queue>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	queue<int> Q;
	cin >> n;

	for (int i = 1; i <= n; i++) Q.push(i);
	while (Q.size() != 1){
		Q.pop();
		int t = Q.front();
		Q.push(t);
		Q.pop();
	}
	cout << Q.front();
}