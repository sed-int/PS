#include <iostream>
#include <stack>
using namespace std;

int main(void){
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	int k, res = 0;
	
	cin >> k;
	while(k--){
		int i;
		cin >> i;
		if (i == 0)	S.pop();
		else S.push(i);
	}
	while (!S.empty())
	{
		res += S.top();
		S.pop();
	}
	cout << res;
}