#include <iostream>
#include <regex>

using namespace std;

void swap(int *, int *);
void swap(char *, char *);
void swap(double *, double *);
int Adder(int num1=1, int num2=2);

namespace BestComImpl {
    void SimpleFunc(void) {
        cout << "BestCom이 정의한 함수" << endl;
    }
}

namespace ProgComImpl {
    void SimpleFunc(void) {
        cout << "ProgComImpl이 정의한 함수" << endl;
    }
}

int main() {
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    cout << num1 << ' ' << num2 << endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    cout << ch1 << ' ' << ch2 << endl;

    double dbl1 = 1.111, dbl2 = 5.555;
    swap(&dbl1, &dbl2);
    cout << dbl1 << ' ' << dbl2 << endl;

    cout << Adder() << endl;
    cout << Adder(5) << endl;
    cout << Adder(3,5) << endl;

    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double *d1, double *d2) {
    double temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

int Adder(int num1, int num2) {
    return num1 + num2;
}

