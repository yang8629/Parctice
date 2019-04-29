#include <iostream>
#include <iomanip>
using namespace std;

const int Max = 100000;
class node
{
private:
	int no;
	char name[10];
	int cmp;
	int math;
	node *ptr;
public:
	void Setno(int n) { no = n; }
	int Getno() { return no; }
	void Setname(char *buffer) {
		for (int i = 0; i < 10; i++)
		{
			name[i] = buffer[i];
		}
	}
	void Getname(char *buffer) {
		for (int i = 0; i < 10; i++)
		{
			buffer[i] = name[i];
		}
	}
	void Setcmp(int score) { cmp = score; }
	int Getcmp() { return cmp; }
	void Setmath(int score) { math = score; }
	int Getmath() { return math; }
	void Setptr(node *write) { ptr = write; }
	node *Getptr() { return ptr; }
};

void ClearInput() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int InputNumber() {
	int n;
	cin >> n;
	if (n <= 0 || !(cin.good()))
	{
		ClearInput();
		return NULL;
	}
	ClearInput();
	return n;
}

int InputName(node *a) {
	char name[10];
	cout << "�п�J�W�l:" << endl;
	cin >> name;
	if (cin.good())
	{
		a->Setname(name);
		ClearInput();
		return 1;
	}
	else
	{
		ClearInput();
		return 0;
	}
}

node *Check(node *head, int n) {
	node *write = NULL;
	write = head;
	while (write != NULL)
	{
		if (n == write->Getno())
		{
			return write;
		}
		else if (n < write->Getno())
		{
			break;
		}
		write = write->Getptr();
	}
	return NULL;
}

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
		while (write != NULL && write->Getno() < p->Getno())
		{
			back = write;
			write = write->Getptr();
		}
		if (back == NULL)
		{
			head = p;
		}
		else
		{
			back->Setptr(p);
		}
		p->Setptr(write);
	}
	return head;
}

node *AddData(node *head) {
	int n;
	node *a;
	cout << "�п�J�@�Ӯy��:" << endl;
	n = InputNumber();
	if (n ==NULL)
	{
		cout << "��J���~" << endl << "�п�J�j��0���Ʀr" << endl << endl;
		return head;
	}
	a = new node();
	a->Setno(n);
	a->Setptr(NULL);
	if (InputName(a) == 0)
	{
		return head;
	}
	else
	{
		char *buffer=new char[10];
		a->Getname(buffer);
	}
	cout << "�п�J�p�����Z:" << endl;
	n = InputNumber();
	if (n == NULL)
	{
		cout << "��J���~" << endl << "�п�J�j��0���Ʀr" << endl << endl;
		return head;
	}
	else
	{
		a->Setcmp(n);
	}
	cout << "�п�J�ƾǦ��Z:" << endl;
	n = InputNumber();
	if (n == NULL)
	{
		cout << "��J���~" << endl << "�п�J�j��0���Ʀr" << endl << endl;
		return head;
	}
	else
	{
		a->Setmath(n);
	}
	if (Check(head, n) == NULL)
	{
		head = Insert(head, a);
		cout << "��ƿ�J���\" << endl;
	}
	else
	{
		cout << "�Ӯy���w�s�b" << endl;
	}
	return head;
}

void Search(node *head) {
	node *write = NULL;
	int n;
	write = head;
	cout << "�п�J�n�d�ߪ��y��:" << endl;
	n = InputNumber();
	if (n != NULL)
	{
		if (Check(head, n) == NULL)
		{
			cout << "�Ӯy�����s�b" << endl;
		}
		else
		{
			cout << "�Ӯy���s�b" << endl;
		}
	}
	else
	{
		cout << "��J���~" << endl;
	}
}

node *DeleteData(node *head) {
	node *write = NULL, *back = NULL, *buffer = NULL;
	int n;
	cout << "�п�J�n�R�����y��:" << endl;
	n = InputNumber();
	if (n != NULL)
	{
		buffer = Check(head, n);
		if (buffer != NULL)
		{
			write = head;
			while (write != buffer)
			{
				back = write;
				write = write->Getptr();
			}
			if (back == NULL)
			{
				head = write->Getptr();
			}
			else
			{
				back->Setptr(write->Getptr());
			}
			delete write;
			cout << "�R���y�� " << n << endl;
		}
		else
		{
			cout << "�y�� " << n << " ���s�b" << endl;
		}
	}
	else
	{
		cout << "�ӿ�J���s�b" << endl;
	}
	return head;
}

int SetArray(node *head, int no[], char name[][1000], int cmp[], int math[]) {
	int i;
	node *p;
	char *buffer = new char[10];
	p = head;
	for (i = 0; i < 1000; i++)
	{
		if (p == NULL)
		{
			break;
		}
		p->Getname(buffer);
		no[i] = p->Getno();
		for (int j = 0; j < 10; j++)
		{
			name[j][i] = buffer[j];
			if (buffer[j] == '\0')
			{
				break;
			}
		}
		cmp[i] = p->Getcmp();
		math[i] = p->Getmath();
		p = p->Getptr();
	}
	return i;
}

void Sorting(node *head,int type) {
	int amount = 0, max = 0, buffer = 0, no[1000] = { NULL }, cmp[1000] = { NULL }, math[1000] = { NULL }, total[1000] = { NULL }, *sort;
	char name[10][1000] = { NULL };
	amount = SetArray(head, no, name, cmp, math);
	sort = new int[amount];
	for (int i = 0; i < amount; i++)
	{
		sort[i] = i;
		total[i] = cmp[i] + math[i];
	}
	for (int i = 0; i < amount; i++)
	{
		max = i;
		for (int j = i + 1; j < amount; j++)
		{
			if (total[max] < total[j])
			{
				max = j;
			}
		}
		buffer = total[i];
		total[i] = total[max];
		total[max] = buffer;
		buffer = sort[i];
		sort[i] = sort[max];
		sort[max] = buffer;
	}
	cout << setw(5) << "�y��" << setw(8) << "�W�l" << setw(10) << "�q�����Z" << setw(10) << "�ƾǦ��Z" << endl;
	for (int i = 0; i < amount; i++)
	{
		int n;
		if (type == 1)
		{
			n = sort[i];
		}
		else
		{
			n = sort[amount - i - 1];
		}
		cout << setw(5) << no[n];
		for (int j = 0; j < 10; j++)
		{
			if (name[j][n] == '\0')
			{
				int count = j;
				if (j < 8)
				{
					for (j; j < 8; j++)
					{
						cout << " ";
					}
					for (int k = 0; k < count; k++)
					{
						cout << name[k][n];
					}
				}
				break;
			}
		}
		cout << setw(10) << cmp[n] << setw(10) << math[n] << endl;
	}
}

void PrintData(node *head) {
	node *write = NULL;
	char *buffer=new char[10];
	int input;
	write = head;
	if (head == NULL)
	{
		cout << "�A�٨S����J����y��";
	}
	else
	{
		cout << "�п�ܱƧǤ覡" << endl << "1. �̮y���ƦC" << endl << "2. ���`���ƦC" << endl << endl;
		input = InputNumber();
		if (input != NULL)
		{
			if (input == 1)
			{

			}
			else if (input == 2)
			{
				cout << "�п�ܱƧǤ覡" << endl << "1. �Ѱ���C" << endl << "2. �ѧC�찪" << endl << endl;
				input = InputNumber();
				if (input != NULL)
				{
					if (input == 1 || input == 2)
					{
						Sorting(head, input);
					}
				}
				else
				{
					cout << "��J���~" << endl;
				}
			}
		}
		else
		{
			cout << "��J���~" << endl;
		}
		//while (write != NULL)
		//{
		//	write->Getname(buffer);
		//	cout << write->Getno() << ' ';
		//	cout << buffer;
		//	cout << ' ' << write->Getcmp() << ' ' << write->Getmath();
		//	write = write->Getptr();
		//	if (write != NULL)
		//	{
		//		cout << " ->  ";
		//	}
		//}
	}
	cout << endl;
	system("pause");
}

void StartList(node *head) {
	int n;	
	while (1)
	{
		cout << "�ǥ͸�ƨt��" << endl << "1. �s�W���" << endl << "2. �d�߸��" << endl << "3. �R�����" << endl << "4. �C�L���" << endl << "5. ���}" << endl << endl;
		while (1)
		{
			n = 0;
			cin >> n;

			if(n > 0 && n < 6)
			{
				break;
			}
			else 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "��J���~" << endl << "�п�J1~5���Ʀr" << endl << endl;
			}
		}
		ClearInput();
		if (n == 1)
		{
			head = AddData(head);
		}
		else if (n == 2)
		{
			Search(head);
		}
		else if (n == 3)
		{
			head = DeleteData(head);
		}
		else if (n == 4)
		{
			PrintData(head);
		}
		else if (n == 5)
		{
			cout << "���}�t��" << endl;
			break;
		}
		cout << endl;
	}
}

int main() {
	node *head = NULL;
	StartList(head);
	cout << endl;
	system("pause");
	return 0;
}