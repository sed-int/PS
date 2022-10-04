#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int M;
	char op, add;
	list<char> line;

	cin >> s;
	for (auto c : s) line.push_back(c);
	auto curr = line.end();
	
	cin >> M;
	while (M--){
		cin >> op;
		if (op == 'L') {
			if (curr != line.begin()) curr--;
		}
		else if (op == 'D'){
			if (curr != line.end()) curr++;
		}	
		else if (op == 'P'){
			cin >> add;
			line.insert(curr, add);
		}
		else {
			if (curr != line.begin()){
				curr--;
				curr = line.erase(curr);
			}
		}
	}
	for (auto c : line) cout << c;
}