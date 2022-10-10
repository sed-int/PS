#include <iostream>
using namespace std;

using ll = long long;
ll a, b, c;

ll func(ll n){
	if (n == 1) return a%c;
	ll k = func(n/2)%c;
	if (n%2 == 0) return k*k%c;
	return k*k*a%c;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	cout << func(b);
}