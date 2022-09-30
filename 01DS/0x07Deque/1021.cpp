#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	deque<int> D;
	for (int i = 1; i <= n; i++)
		D.push_back(i);
	while (m--){
		int t;
		cin >> t;
		int idx = find(D.begin(), D.end(), t) - D.begin();
		while (D.front() != t){
			if (idx > (int)D.size()/2){
				D.push_front(D.back());
				D.pop_back();
			}
			else {
				D.push_back(D.front());
				D.pop_front();
			}
			cnt++;
		}
		D.pop_front();
	}
	cout << cnt;
}