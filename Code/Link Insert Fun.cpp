#include <iostream>
using namespace std;

class node
{
public:
	int no;
	node *ptr;
};

node *Insert(node *head, node *p) {
	node *back = NULL, *write = NULL;
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		back = NULL;
		write = head;
		while (write != NULL && write->no < p->no)
		{
			back = write;
			write = write->ptr;
		}
		if (back == NULL)
		{
			head = p;
		}
		else
		{
			back->ptr = p;
		}
		p->ptr = write;
	}
	return head;
};

int main() {
	node *head = NULL, *write = NULL, *a = NULL;
	int n = 0;
	cout << "請輸入座號" << endl;
	while (1)
	{
		cin >> n;
		if (n <= 0 || !(cin.good()))
		{
			cin.clear();
			cout << "結束輸入" << endl << endl;
			break;
		}
		a = new node();
		a->no = n;
		a->ptr = NULL;
		head = Insert(head, a);
	}
	write = head;
	while (write != NULL)
	{
		cout << write->no;
		write = write->ptr;
		if (write != NULL)
		{
			cout << " ->  ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}