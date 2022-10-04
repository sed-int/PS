#include <iostream>
#include <stack>
using namespace std;

#define X first
#define Y second
int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> S;
	for (int i = 1; i <= n; i++){
		int t;
		cin >> t;
		while (!S.empty() && S.top().X < t)
			S.pop();
		if (S.empty())
			cout << "0 ";
		else
			cout << S.top().Y << " ";
		S.push({t, i});
	}
}