#include <iostream>
using namespace std;
class Array {
private:
    int n = 0;
    int *a = new int [n];
public:
    void enter(string x);
    void push(int x);
    int pop();
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
void Array::push(int x){

    int *arr1=new int[n+1];
    for(int i=0;i<n;i++){
        arr1[i]=a[i];
    }
    arr1[n]=x;
    delete[] a;
    a=arr1;
    n=n+1;

}
int Array::pop() {
    if (n==0){
        cout << "Underflow";
        return 0;
    }
    int *arr1 = new int[n - 1];
    for (int i = 0; i < n - 1; i++) {
        arr1[i] = a[i];
    }
    int temp=a[n-1];
    delete[] a;
    a = arr1;
    n = n - 1;
    return temp;

}

void Array::enter(string x) {
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') {

            switch (x[i]) {
                case '+': {
                    int s = a[n - 2] + a[n - 1];
                    pop();
                    pop();
                    push(s);
                }
                    break;
                case '-': {
                    int s = a[n - 2] - a[n - 1];
                    pop();
                    pop();
                    push(s);
                }
                    break;
                case '*': {
                    int s = a[n - 2] * a[n - 1];
                    pop();
                    pop();
                    push(s);
                }
                    break;
                case '/': {
                    int s = a[n - 2] / a[n - 1];
                    pop();
                    pop();
                    push(s);
                }
                    break;
            }
        }
        else {
            int k=x[i]-'0';
            push(k);
        }


    }
}


int main() {
    Array a;
    string s;
    cout << "Enter" << endl;
    cin >> s;
    int k;
    a.enter(s);
    cout << a.pop();
    return 0;
}