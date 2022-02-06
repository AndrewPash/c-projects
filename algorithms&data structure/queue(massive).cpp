#include <iostream>
using namespace std;
class Array {
private:
    int n = 0;
    char *a = new char [n];
public:
    void push(char x);
    char pop();
    void show();
};
void Array::show() {
    if (n == 0) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
void Array::push(char x){
    char *arr1=new char[n+1];
    for(int i=0;i<n;i++){
        arr1[i]=a[i];
    }
    arr1[n]=x;
    delete[] a;
    a=arr1;
    n=n+1;

}
char Array::pop() {
    char *arr1 = new char[n];
    arr1[n-1]=a[0];
    for (int i = 1; i < n; i++) {
        arr1[i-1] = a[i];
    }
    char temp=a[0];
    delete[] a;
    a = arr1;
    return temp;

}
int main() {
    Array a;
    int k;
    while(true){
        cout << "Choose function:1-push,2-pop,3-show" << endl;
        cin >> k;
        switch(k){
            case 1:
                cout << "Enter element" << endl;
                char x;
                cin >> x;
                a.push(x);
                break;
            case 2:
                cout << a.pop() << endl;
                break;
            case 3:
                a.show();
                break;
            default:
                return 0;
        }

    }
    return 0;
}