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
    void enqueue(int x);
    int dequeue();
    bool check();


};

void stack::enqueue(int x) {

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

int stack::dequeue() {
    if(!check()){
        cout <<"Underflow" << endl;
        return 0;
    }
    else if (Head->Next != NULL) {
        int temp=Head->x;
        Head->Next->Prev=NULL;
        Head=Head->Next;
        return temp;
    }
    else{
        int temp=Head->x;
        Head=Tail=NULL;
        return temp;
    }
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
                a.enqueue(k);
                break;
            case 2:
                cout << a.dequeue() << endl;
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