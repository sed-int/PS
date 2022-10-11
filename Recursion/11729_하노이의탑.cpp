#include <iostream>
using namespace std;

void move(int from, int to)
{
    cout << from << " " << to << '\n';
}

void hanoi(int n, int from, int by, int to)
{
    if(n == 0) return;
    hanoi(n - 1, from, to, by);
    move(from, to);
    hanoi(n - 1, by, from, to);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	cout << (1<<k) - 1 << '\n';
	hanoi(k, 1, 2, 3);
}