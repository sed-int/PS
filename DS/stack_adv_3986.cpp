#include <iostream>
#include <stack>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	while (n--){
		string s;
		cin >> s;
		stack<int> S;
		for (auto c : s){
			if (!S.empty() && S.top() == c) S.pop();
			else S.push(c);
		}
		if (S.empty()) ans++;
	}
	cout << ans << "\n";
}