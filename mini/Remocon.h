#include <iostream>
#include <cstring>
using namespace std;

class Remocon {
    Remocon *romo;
public:
    Remocon() {
        romo = new Remocon();
    }
    ~Remocon() {}
    void func_R(){}; //전원버튼
    void func_T(){}; //시간설정
    virtual void func_W();
    virtual void func_A();
    virtual void func_S();
    virtual void func_D();
    virtual void func_X();
    void insertDevice();//기기등록
    void deleteDevice();//기기해제
};

class Television : public Remocon {
    void func_W();//채널UP
    void func_A();//볼륨DOWN
    void func_D();//볼륨UP
    void func_X();//채널DOWN
};

class AirConditional : public Remocon {
    void func_W();//온도UP
    void func_A();//풍량DOWN
    void func_D();//풍량UP
    void func_X();//온도DOWN
};

class AirCleaner : public Remocon {
    void func_W();//방향_상
    void func_A();//방향_좌 / 풍량down
    void func_D();//방향_우 / 풍량up
    void func_X();//방향_하
    void func_S();//방향 풍량 전환
};

class clock : public Remocon {
    void func_W();//시간up
    void func_A();//분down
    void func_D();//분up
    void func_X();//시간down
}