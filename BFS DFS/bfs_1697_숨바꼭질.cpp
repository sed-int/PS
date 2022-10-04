#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int dist[100002];
int main(void){
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	fill(dist, dist+100001, -1);
	dist[n] = 0;
	queue<int> Q;
	Q.push(n);
	while (!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int nxt : {cur-1, cur+1, 2*cur}){
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur]+1;
			Q.push(nxt);
		}
	}
	cout << dist[k];
}