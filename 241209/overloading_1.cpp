#include <iostream>

using namespace std;

void MyFunc(void) {
    cout << "MyFunc(void) called" << endl;
}

void MyFunc(char c) {
    cout << "MyFunc(char) called" << endl;
}

void MyFunc(int a, int b) {
    cout << "MyFunc(int a, int b) called" << endl;
}

int main(void) {
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);

    return 0;
}