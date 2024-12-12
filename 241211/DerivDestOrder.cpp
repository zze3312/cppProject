#include <iostream>
using namespace std;

class SoBase {
    int baseNum;
public:
    SoBase(int n) : baseNum(n) {
        cout << "SoBase() : " << baseNum << endl;
    }
    ~SoBase() {
        cout << "~SoBase() : " << baseNum << endl;
    }
};

class SoDerived : public SoBase {
    int derivNum;
public:
    SoDerived(int n) : SoBase(n), derivNum(n) {
        cout << "SoDerived() : " << derivNum << endl;
    }
    ~SoDerived() {
        cout << "~SoDerived() : " << derivNum << endl;
    }
};

int main() {
    SoDerived drv1(15);
    SoDerived drv2(27);

    return 0;
}