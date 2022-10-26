#include <iostream>
using namespace std;

int freq[2000001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  cin >> n;
  while (n--) {
    cin >> t;
    freq[t+1000000]++;
  }
  for (int i = 0; i <= 2000000; i++)
    while (freq[i]--) cout << i - 1000000 << '\n';
}