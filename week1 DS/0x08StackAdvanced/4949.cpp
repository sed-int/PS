#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true){
		stack<char> S;
		string s;
		getline(cin, s);
		if (s == ".") break;
		bool isValid = true;
		for (auto c : s){
			if (c == '(' || c == '[')
				S.push(c);
			else if (c == ')'){
				if (S.empty() || S.top() != '('){
					isValid = false;
					break;
				}
				S.pop();
			}
			else if (c == ']'){
				if(S.empty() || S.top() != '['){
					isValid = false;
					break;
				}
				S.pop();
			}
		}
		if(!S.empty()) isValid = false;
		if(isValid) cout << "yes\n";
		else cout << "no\n";
	}
}