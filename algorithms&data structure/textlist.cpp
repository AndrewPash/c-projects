#include <iostream>
#include <string.h>

using namespace std;
struct Node
{
    char * x;
    Node *Next, *Prev;
};

class List
{
    Node *Head, *Tail;
public:
    List():Head(NULL),Tail(NULL){};
    ~List();
    void ShowFHead();
    void ShowFTail();
    void Add(char *x);
    void Addmiddle(int index);
    void AddHead();
    void DeleteHead();
    void DeleteTail();
    void Task();
    void Delbyindex(int index);
    void dod();
};

List::~List()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

void List::Add(char *x) {

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

    void List::ShowFHead() {
        Node *temp=Head;

        while (temp != NULL)
        {
            if(temp->Next==NULL){
                cout << temp->x << '.';
                temp=temp->Next;
            }
            else {
                cout << temp->x << " ";
                temp = temp->Next;
            }
        }
        cout << "\n";
    }
    void List::ShowFTail() {
        Node *temp = Tail;
        if (Head == NULL) {
            cout << "List is empty" << endl;
        } else {
            while (temp!= NULL) {
                if (temp == Head) {
                    cout << temp->x << '.';
                    temp=temp->Prev;
                } else{
                    cout << temp->x << " ";
                temp = temp->Prev;
            }
            }
            cout << "\n";
        }
    }
    void List::Addmiddle(int index){
    if (Head==NULL){
        cout << "List is empty" << endl;
        return;
    }
          if(index==1){
            AddHead();
            return;
        }
        Node *temp=Head;
        for(int i=1;i<index;i++){
            if(temp->Next==NULL){
                char* word=new char[255];
                cout << "Enter word" << endl;
                cin >> word;
                if (word == NULL || word[0] == ' ') {
                    cout << "You entered a empty word";
                }
                Add(word);
                return;
            }
            temp=temp->Next;
        }
        if(temp==NULL){
            char* word=new char[255];
            cout << "Enter word" << endl;
            cin >> word;
            if (word == NULL || word[0] == ' ') {
                cout << "You entered a empty word";
            }
            Add(word);

        }



            char* word=new char[255];
            cout << "Enter word" << endl;
            cin >> word;
            if (word == NULL || word[0] == ' ') {
                cout << "You entered a empty word";
            }
            Node *temp1=new Node;
        temp->Prev->Next=temp1;
        temp1->Next=temp;
        temp1->Prev=temp->Prev;
        temp->Prev=temp1;
        temp1->x=word;




}
void List::AddHead() {
    char* word=new char[255];
    Node *temp = new Node;
    cout << "Enter word" << endl;
    cin >> word;
    if (word == NULL || word == " ") {
        cout << "You entered a empty word";
    }
    temp->x = word;
    if (Head != NULL)
    {
        temp->Next = Head;
        Head->Prev = temp;
        temp->Prev=NULL;
        Head=temp;

    } else
    {
        temp->Prev = NULL;
        temp->Next=NULL;
        Head = Tail = temp;
    }
}

void List::DeleteHead(){
    if(Head==NULL){
        cout <<"List is empty" << endl;
    }
    else if(Head->Next==NULL){
        Head=NULL;
    }
    else if(Head!=NULL) {
        delete [] Head->x;
        Head->Next->Prev=NULL;
        Head = Head->Next;
    }

};
void List::DeleteTail() {
    if(Head==NULL){
        cout <<"List is empty" << endl;
    }
    else if (Head->Next != NULL) {
        delete [] Tail->x;
        Tail = Tail->Prev;
        Tail->Next->Prev = NULL;
        Tail->Next=NULL;

    } else if(Head!=NULL) {
         DeleteHead();

    }
    else {
        cout << "List is empty" << endl;
    }
}
void List::Task(){
    if(Head!=NULL){
        if(Head->Next!=NULL){
            Node * temp=Head;
            temp=Head->Next;
                while(temp!=NULL && temp->x[0]!=Head->x[0]){
                    int size=strlen(temp->x);
                    if(size%2==0){
                        char* newword=new char[size+1];
                        newword[0]=temp->x[0];
                        for(int i=0;i<size;i++){
                            newword[i+1]=temp->x[i];

                        }
                        delete [] temp->x;
                        temp->x=newword;
                        cout << temp->x;
                        temp=temp->Next;
                    }
                    else {
                        temp->x[size-1]='\0';
                        cout << temp->x;
                        temp=temp->Next;


                    }

                    cout << "\n";
                }
            }
        else{
            cout << "Less than two words" << endl;
        }
        }
    }

void List::Delbyindex(int index) {
    if(Head==NULL){
        cout << "List is empty";
    }
    if(index==1){
        DeleteHead();
    }
    else if(Head->Next==NULL){
        DeleteHead();
    }
    else {
        Node *temp = Head;
        for (int i = 1; i < index; i++) {
            temp = temp->Next;

            if (temp == NULL || temp->Next == NULL) {
                DeleteTail();
                return;
            }
        }
        temp->Prev->Next=temp->Next;
        temp->Next->Prev=temp->Prev;
        delete [] temp->x;
    }

}


void List::dod() {
    if(Head==NULL){
        cout << "List is empty";
    }
    else {
        Node *temp = Head;

        while (temp != NULL) {
            if (!strcmp(temp->x,"cat")) {
                int size = strlen(temp->x);
                char *word = new char[size];
                for (int i = 0; i < size; i++) {
                    word[i] = temp->x[size - i - 1];
                }
                temp->x = word;
            }
            temp=temp->Next;
        }
    }
}


int main() {
      List spisok;
      int k;
      string text;
    char* word=new char[255];
      cout << "Enter text" << endl;
      getline(cin,text);
      if(text==""){
          cout<< "Error:text is empty";
      }
      int siz=text.length()+1;
      char *arr=new char[siz];
      for(int i=0;i<siz;i++){
          arr[i]=text[i];
      }
      char * split;
      split=strtok(arr," ,");
      while(split!=NULL)
      {
          spisok.Add(split);
          split=strtok(NULL," .");
      }
      spisok.ShowFHead();
      while(true) {
          cout
                  << "Choose function:1-add to the beginning;2-add to the end;3-add by index;4-delete head;5-delete tail;6-delete by index;7-perform the task"
                  << endl;
          cin >> k;
          switch (k) {
              case 1:
                  spisok.AddHead();
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  break;
              case 2:

                  cout << "Enter word" << endl;
                  cin >> word;
                  if (word == NULL || word == " ") {
                      cout << "You entered a empty word";
                      break;
                  }
                  else {


                      spisok.Add(word);
                      spisok.ShowFHead();
                      spisok.ShowFTail();
                      break;
                  }

              case 3:
                  int n;
                  cout << "Enter index" << endl;
                  cin >> n;
                  spisok.Addmiddle(n);
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  break;
              case 4:
                  spisok.DeleteHead();
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  break;
              case 5:
                  spisok.DeleteTail();
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  break;
              case 6:
                  cout << "Enter index" << endl;
                  cin >> n;
                  spisok.Delbyindex(n);
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  break;
              case 7:
                  spisok.Task();
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  break;
              default:
                  spisok.dod();
                  spisok.ShowFHead();
                  spisok.ShowFTail();
                  return 0;
          }
      }
}