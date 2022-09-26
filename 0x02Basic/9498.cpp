#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int grade;
	cin >> grade;
	if (grade > 89) cout << 'A';
	else if (grade > 79 && grade < 90) cout << 'B';
	else if (grade > 69 && grade < 80) cout << 'C';
	else if (grade > 59 && grade < 70) cout << 'D';
	else cout << 'F';
}