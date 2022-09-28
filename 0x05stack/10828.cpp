#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> S;
	int n;
	cin >> n ;
	while(n--){
		string op;
		cin >> op;
		if (op == "push"){
			int v;
			cin >> v;
			S.push(v);
		}
		else if (op == "top"){
			if (S.empty())
				cout << -1 << '\n';
			else
				cout << S.top() << '\n';
		}
		else if (op == "pop"){
			if (S.empty())
				cout << -1 << '\n';
			else {
				cout << S.top() << '\n';
				S.pop();
			}
		}
		else if (op == "size"){
			cout << S.size() << '\n';
		}
		else { //empty
			cout << (int)S.empty() << '\n';
		}
		
	}
}