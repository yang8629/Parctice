#include <iostream>
using namespace std;

class node
{
public:
	int no;
	node *ptr;
};

int main() {
	node *head = NULL, *write = NULL;
	int n = 0;
	while (1)
	{
		cin >> n;
		if (n <= 0 || !(cin.good()))
		{
			cin.clear();
			cout << "µ²§ô¿é¤J" << endl << endl;
			break;
		}
		if (head == NULL)
		{
			head = new node();
			write = head;
		}
		else
		{
			write->ptr = new node;
			write = write->ptr;
		}
		write->no = n;
		write->ptr = NULL;
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
