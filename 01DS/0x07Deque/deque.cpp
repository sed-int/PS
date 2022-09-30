#include <iostream>
using namespace std;

const int MX = 1000000;
int deque[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
	deque[--head] = x;
}

void push_back(int x){
	deque[tail++]= x;
}

void pop_front(){
	if (head != MX) head++;
}

void pop_back(){
	if (tail != MX) tail--;
}

int front(){
	return (deque[head]);
}

int back(){
	return (deque[tail-1]);
}

void test(){
  push_back(30); // 30
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 30
  push_front(25); // 25 30
  push_back(12); // 25 30 12
  cout << back() << '\n'; // 12
  push_back(62); // 25 30 12 62
  pop_front(); // 30 12 62
  cout << front() << '\n'; // 30
  pop_front(); // 12 62
  cout << back() << '\n'; // 62
}

int main(void){
  test();
}