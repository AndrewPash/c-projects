#include <iostream>
using namespace std;
class Array {
private:
    int n = 10;
    int g=0;
    int h=0;
    double *a = new double [n];
public:
    void push1(double x);
    void push2(double x);
    double pop1();
    double pop2();
    void pushmiddle(int index,double x);
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
void Array::push1(double x){
    if(g+h>=10){
        cout << "Overflow";
    }
    else {
        if (g == 0) {
            pushmiddle(1, x);
            g = g + 1;
        } else {
            pushmiddle(g + 1, x);
            g = g + 1;
        }
    }

}
void Array::push2(double x){
    if(g+h>=n)
    {
        cout << "Overflow";
    }
    else {
        pushmiddle(n - h + 1, x);
        h = h + 1;
    }

}
void Array::pushmiddle(int index,double x) {
if(index>n){
    cout << "Out of bounds" << endl;
}
else {
    a[index-1]=x;
}

}
double Array::pop1() {
    if (g==0){
        cout << "Underflow";
        return 0;
    }
    double *arr1 = new double[n - 1];
    for (int i = 0; i < g - 1; i++) {
        arr1[i] = a[i];
    }
    for (int i = g; i < n; i++) {
        arr1[i - 1] = a[i];
    }
    double temp=a[g-1];
    delete[] a;
    a = arr1;
    n = n - 1;
    g=g-1;
    return temp;

}
double Array::pop2() {
    if (n-g==0){
        cout << "Underflow";
        return 0;
    }
    double *arr1 = new double[n - 1];
    for (int i = 0; i < g+1; i++) {
        arr1[i] = a[i];
    }
    for (int i = g+1; i < n; i++) {
        arr1[i - 1] = a[i];
    }
    double temp=a[g];
    delete[] a;
    a = arr1;
    n = n - 1;
    return temp;

}
int main() {
    Array a;
    int k;
    while(true){
        cout << "Choose function:1-push to first,2-pop first,3-push to second,4-pop second,5-show" << endl;
        cin >> k;
        switch(k){
            case 1:
                cout << "Enter element" << endl;
                double x;
                cin >> x;
                a.push1(x);
                break;
            case 2:
                cout << a.pop1() << endl;
                break;
            case 3:
                cout << "Enter element" << endl;
                double y;
                cin >> y;
                a.push2(y);
                break;
            case 4:
                cout << a.pop2() << endl;
                break;
            case 5:
                a.show();
                break;
            default:
                return 0;
        }

    }
    return 0;
}