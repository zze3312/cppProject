#include <iostream>

using namespace std;

class SoSimple {
private:
    int num1;
    int num2;

public:
    SoSimple(int n1, int n2) : num1(n1), num2(n2) { }
    SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2) {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData() {
        cout << "num1 = " << num1 << endl;
        cout << "num1 = " << &num1 << endl;
        cout << "num2 = " << num2 << endl;
        cout << "num2 = " << &num2 << endl;
    }
};

int main() {
    SoSimple sim1(15, 20);
    cout << "생성 및 초기화 직전" << endl;
    SoSimple sim2 = sim1;
    cout << "생성 및 초기화 직후" << endl;
    //sim1.ShowSimpleData();
    sim2.ShowSimpleData();
    return 0;
}