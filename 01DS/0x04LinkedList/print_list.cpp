#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

int main(void){
	//freopen("input.txt", "r", stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	int n;
	cout << "How many?\n";
	cin >> n;
	//cin >> n >> k;

	Node *head, *newnode, *temp;
	head = 0;
	for (int i = 1; i <= n; i++){
		newnode = new Node();
		newnode->data = i;
		newnode->next = 0;
		if (head == 0) {
			head = newnode;
			temp = newnode;
		}
		else {
			temp->next = newnode;
			temp = temp->next;
		}
	}
	temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}