#include <iostream>
#include <algorithm>
using namespace std;

int div = 1000000000;
int n, d[102];
int main(void){
    cin >> n;
    d[1] = 9;
    d[2] = 17;
    for (int i = 3; i <= n; i++){
        d[i] = (d[i-1] * 2 - 1) % div;
    }
    cout << d[n];
}