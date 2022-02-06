#include <iostream>
using namespace std;

struct Node
{
    int x;
    Node *Next, *Prev;
};

class stack
{
    Node *Head, *Tail,*n;

public:
    stack():Head(NULL),Tail(NULL){};
    ~stack();
    void show();
    void push(int x);
    int pop();
    bool check();


};

void stack::push(int x) {

    Node *temp = new Node;
    temp->Next = NULL;
    temp->x = x;

    if (Head != NULL)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    } else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
    }
}

int stack::pop() {
    if(!check()){
        cout <<"Underflow" << endl;
    }
    else if (Head->Next != NULL) {
        int temp=Tail->x;
        Tail->x=NULL;
        Tail = Tail->Prev;
        Tail->Next->Prev = NULL;
        Tail->Next = NULL;
        return temp;
    }
    else{
        return Head->x;
    }

     return 0;
}

void stack::show() {
    Node *temp=Head;
    while (temp != NULL) {
            cout << temp->x;
            temp = temp->Next;
        }
    }


stack::~stack() {

        while (Head)
        {
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }

}

bool stack::check() {
    if(Tail==NULL) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    stack a;
    int n;
    int k;
    while (true) {
        cout << "1-push,2-pop,3-check " << endl;
        cin >> n;
    switch (n) {
        case 1:
            cin >> k;
            a.push(k);
            break;
        case 2:
            cout << a.pop() << endl;
            break;
        case 3:
            if(a.check()){
                cout << "Stack is not empty" << endl;
            }
            else
            {
                cout << "Stack is empty" << endl;
            }
            break;
        default:
            return 0;

    }
}
}