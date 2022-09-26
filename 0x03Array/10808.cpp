#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int alpha[26];	
	
	cin >> str;	
	fill(alpha, alpha+25, 0);
	for (auto c : str)
		alpha[c-97]++;
	for (int i = 0; i < 26; i++)
		cout << alpha[i] << ' ';
}