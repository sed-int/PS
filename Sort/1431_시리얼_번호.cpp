#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n;
string S;
vector<string> V;

bool cmp (string& a, string& b){
  int len_a = a.size(), len_b = b.size();
  int sum_a = 0, sum_b = 0;
  if(len_a != len_b) return len_a < len_b;

  for(int i = 0; i < len_a; i++){ 
    if(isdigit(a[i])) sum_a += (a[i] - '0');
  }
  for(int i = 0; i < len_b; i++){
    if(isdigit(b[i])) sum_b += (b[i] - '0');
  }
  if(sum_a != sum_b) return sum_a < sum_b;
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> S;
    V.push_back(S);
  }
  sort(V.begin(), V.end(), cmp);
  for(auto i : V) cout << i << '\n';
}