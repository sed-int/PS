#include <iostream>
#include <queue>
using namespace std;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int n;
	cin >> n;
	while (n--){
		string s;
		cin >> s;
		if (s == "push"){
			int t;
			cin >> t;
			Q.push(t);
		}
		else if (s == "pop"){
			if (Q.empty())
				cout << -1 << "\n";
			else{
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (s == "size"){
			cout << Q.size() << "\n";
		}
		else if (s == "empty"){
			if (Q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "front"){
			if (Q.empty())
				cout << -1 << "\n";
			else
				cout << Q.front() << "\n";
		}
		else { // back
			if (Q.empty())
				cout << -1 << "\n";
			else
				cout << Q.back() << "\n";
		}
	}
}