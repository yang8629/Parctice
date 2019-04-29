#include <iostream>
#include<string>
using namespace std;

class node
{
    int no;
    node *ptr;
    char name[10];
    int math;
    int pc;
public:
    void Writeno(int data) { no = data; }
    int Readno() { return no; }
    void Writemath(int data) { math = data; }
    int Readmath() { return math; }
    void Writepc(int data) { pc = data; }
    int Readpc() { return pc; }
    void Writeptr(node *p) { ptr = p; }
    node * Readptr() { return ptr; }
    void Writename(char *data) {
        for (int i=0; i<10; i++) {
            name[i] = data[i];
        }
    }
    void Readname(char *data) {
        for (int i=0; i<10; i++) {
            data[i] = name[i];
        }
    }
};

node *Insert(node *head, node *p) {
    node *back = NULL, *follow = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        back = NULL;
        follow = head;
        while (follow != NULL && follow->Readno() < p->Readno() )
        {
            back = follow;
            follow = follow->Readptr();
        }
        if (back == NULL)
        {
            head = p;
        }
        else
        {
            back->Writeptr(p);
        }
        p->Writeptr(follow);
    }
    return head;
}

int Check(node *head, int n) {
    node *follow = NULL;
    follow = head;
    while (follow != NULL)
    {
        if (n == follow->Readno() )
        {
            return 0;
        }
        else if (n < follow->Readno())
        {
            break;
        }
        follow = follow->Readptr();
    }
    return 1;
}



node *AddData(node *head) {
    int n;
    char nam[10];
    int m;
    int c;
    node *a;
    cout << "輸入座號" << endl;
    cin >> n;
    cout << "輸入名字" << endl;
    cin >> nam;
    cout << "輸入數學成績" << endl;
    cin >> m;
    cout << "輸入電腦成績" << endl;
    cin >> c;
    if (n <= 0 || !(cin.good()))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "輸入錯誤" << endl << "請輸入大於0的數字" << endl << endl;
        return head;
    }
    a = new node();
    a->Writeno(n);
    a->Writename(nam);
    a->Writemath(m);
    a->Writepc(c);
    a->Writeptr(NULL);
    if (Check(head, n))
    {
        head = Insert(head, a);
    }
    else
    {
        cout << "該座號已存在" << endl;
    }
    return head;
}

void Search(node *head) {
    node *follow = NULL;
    int n, exist = 0;
    char *data= new char[10];
    follow = head;
    cout << "輸入座號" << endl;
    cin >> n;
    if (n > 0 && cin.good())
    {
        while (follow != NULL)
        {
            if (n == follow->Readno() )
            {
                follow->Readname(data);
                exist = 1;
                break;
            }
            else if (n < follow->Readno() )
            {
                break;
            }
            follow = follow->Readptr();
        }
        if (exist)
        {
            cout << n << "號 "<< data <<" 數學成績:" << follow->Readmath() << "分 電腦成績:" << follow->Readpc() << "分";
        }
        else
        {
            cout << "該座號不存在";
        }
        cout << endl;
    }
}

node *DeleteData(node *head) {
    node *follow = NULL, *back = NULL;
    bool dele = false;
    int n;
    cout << "輸入座號" << endl;
    cin >> n;
    follow = head;
    while (follow != NULL)
    {
        if (n == follow->Readno())
        {
            dele = true;
            break;
        }
        else if (n < follow->Readno() )
        {
            break;
        }
        back = follow;
        follow = follow->Readptr();
    }
    if (dele)
    {
        if (back == NULL)
        {
            head = follow->Readptr();
        }
        else
        {
            back->Writeptr( follow->Readptr() );
        }
        delete follow;
        cout << "刪除 " << n << endl;
    }
    else
    {
        cout << "資料 " << n <<"不存在"<< endl;
    }
    return head;
}

int Transfer(node *head,int *no,string *name,int *math,int *pc){
    int i;
    char *data= new char[10];
    node *follow = NULL;
    follow = head;
    for (i=0; i<1000; i++) {
        follow->Readname(data);
        no[i] = follow->Readno();
        name[i].assign(data);
        math[i] = follow->Readmath();
        pc[i] = follow->Readpc();
        follow = follow->Readptr();
        if (follow==NULL) {
            break;
        }
    }
    return i;
}

void Cul(node *head,int n){
    int i,count;
    int max;
    int t;
    string tt;
    int no[1000]={NULL};
    string name[1000]={NULL};
    int math[1000]={NULL};
    int pc[1000]={NULL};
    int total[1000]={NULL};
    count=Transfer(head,no,name,math,pc)+1;
    for (i=0; i<count; i++) {
        total[i] = math[i]+pc[i];
    }
    for (i=0; i<count; i++) {
        max=i;
        for (int j=i+1; j<count; j++) {
            if (total[j]==0) {
                break;
            }
            if (total[max]<total[j]) {
                max=j;
            }
        }
        t=no[i];no[i]=no[max];no[max]=t;
        tt=name[i];name[i]=name[max];name[max]=tt;
        t=math[i];math[i]=math[max];math[max]=t;
        t=pc[i];pc[i]=pc[max];pc[max]=t;
        t=total[i];total[i]=total[max];total[max]=t;
    }
    for (i=0; i<count; i++) {
        cout<< no[i] << "號 " << name[i] << " 數學成績:" << math[i] << "分 " << "電腦成績:" << pc[i] << "分" << endl;
    }
}

void PrintData(node *head) {
    Cul(head, 1);
//    char *data= new char[10];
//    node *follow = NULL;
//    follow = head;
//    follow->Readname(data);
//        while (follow != NULL)
//        {
//            cout << follow->Readno() << "號 " << data << " 數學成績:" << follow->Readmath() << "分 電腦成績:" << follow->Readpc() << "分";
//            follow = follow->Readptr();
//            if (follow != NULL)
//            {
//                cout << endl;
//            }
//        }
    cout << endl;
    system("pause");
    cout << endl;
}


void StartList(node *head) {
    int n;
    while (1)
    {
        cout << "請輸入1~5的數" << endl << "1.輸入資料" << endl << "2.搜尋資料" << endl << "3.刪除資料" << endl << "4.列印資料" << endl << "5.離開" << endl << endl;
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
                cout << "輸入錯誤" << endl << "請輸入1~5" << endl << endl;
            }
        }
        if (n == 1)
        {
            head = AddData(head);
//            cout << "輸入" << endl;
        }
        else if (n == 2)
        {
            Search(head);
//            cout << "搜尋" << endl;
        }
        else if (n == 3)
        {
            head = DeleteData(head);
//            cout << "刪除" << endl;
        }
        else if (n == 4)
        {
            PrintData(head);
//            cout << "列印" << endl;
        }
        else if (n == 5)
        {
            cout << "離開" << endl;
            break;
        }
        cout << endl;
    }
}




int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    node *head = NULL;
    StartList(head);
    cout << endl;
    system("pause");
    return 0;
}
