#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> a[100002];
int N, ans;
int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a+N);
	int t = 0;
	for (int i = 0; i < N; i++){
		if(t > a[i].second) continue;
		ans++;
		t = a[i].first;
	}
	cout << ans;
}