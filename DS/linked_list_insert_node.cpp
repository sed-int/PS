#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
}

node *head; //global variable;
int n, x;
int main(void)
{
	head = NULL; //empty list;
	cout << "How many numbers?\n";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Enter the number \n";
		cin >> x;
		Insert(x);
		print();
	}
}

void Insert(int x)
{
	node* tmp = new node();
	tmp->data = x;
	tmp->next = NULL;
	if (head == NULL)
	{
		head = tmp;
	}
}
