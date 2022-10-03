#include <iostream>
#include <stack>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, i = 1;
	stack<int> S;
	string ans;
	
	cin >> n;
	while (n--){
		int t;
		cin >> t;
		while (i <= t){
			S.push(i++);
			ans += "+\n";
		}
		if (S.top() != t) {
			cout << "NO\n";
			return (0);
		}
		S.pop();
		ans += "-\n";
	}
	cout << ans;
}