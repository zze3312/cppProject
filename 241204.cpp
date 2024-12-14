#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

class Person {
    int age; //나이는 0~100의 정수
    const string name;

public:
    void printInfo();
    void setAge(int age);
    int getAge() const;
};

int main() {

    Person *personList = new Person[10];
    for (int i = 0; i < 10; i++) {
        personList[i].setAge(i);
    }

    return 0;
}

void Person::printInfo(){
    cout << "이름은 " << name << endl;
    cout << "나이는 " << age << "살입니다" << endl;
}

void Person::setAge(int age) {
    if (age > 100 || age < 0) {
        cout << "age : "<< age << "\n잘못된 나이 입니다." << endl;
    }else {
        cout << "age : "<< age << "\n정상적인 나이 입니다." << endl;
        this -> age = age;
    }
}

int Person::getAge() const {
    return age;
}