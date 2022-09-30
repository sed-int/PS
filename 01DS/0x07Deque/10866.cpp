#include <iostream>
#include <deque>
using namespace std;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> D;
	int n;
	cin >> n;
	while (n--){
		string s;
		cin >> s;
		if (s == "push_back") {
			int t;
			cin >> t;
			D.push_back(t);
		}
		else if (s == "push_front"){
			int t;
			cin >> t;
			D.push_front(t);
		}
		else if (s == "front"){
			if (D.empty())
				cout << -1 << "\n";
			else
				cout << D.front() << "\n";
		}			
		else if (s == "back"){
			if (D.empty())
				cout << -1 << "\n";
			else
				cout << D.back() << "\n";
		}
		else if (s == "pop_front"){
			if (D.empty())
				cout << -1 << "\n";
			else{
				cout << D.front() << "\n";
				D.pop_front();
			}
		}
		else if (s == "pop_back"){
			if (D.empty())
				cout << -1 << "\n";
			else{
				cout << D.back() << "\n";
				D.pop_back();
			}
		}
		else if (s == "size")
			cout << D.size() << "\n";
		else { //empty
			cout << D.empty() << "\n";
		}		
	}
}