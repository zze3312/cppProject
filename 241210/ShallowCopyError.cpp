#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char *name;
    int age;
public:
    Person(char *myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    Person(const Person &copy) : age(copy.age) {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }

    void ShowPersoninfo() const {
        cout << "Name: " << name << endl;
        cout << "Name: " << &name << endl;
        cout << "Age: " << age << endl;
        cout << "Age: " << &age << endl;
    }

    ~Person() {
        delete []name;
        cout << "called Destructor" << endl;
    }
};

int main() {
    Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowPersoninfo();
    man2.ShowPersoninfo();
    return 0;
}
