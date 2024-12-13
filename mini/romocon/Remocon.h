#ifndef RTSET_H
#define RTSET_H

#include <iostream>

using namespace std;

struct Device {
    string position; //기기장소
    string type; //기기종류
};

class Remocon {
    Device *deviceInfo;
    static Device *deviceList[];
    static int deviceCnt;
    bool power;
    bool offTimeYn;
    string offTime;

public:
    Remocon(); //기기등록
    ~Remocon(); //기기해제
    void func_R(); //전원버튼
    void func_T(); //시간설정
    virtual void func_W();
    virtual void func_A();
    virtual void func_S();
    virtual void func_D();
    virtual void func_X();
    virtual void func_C(); //상태확인
    void showDevice(); //기기목록
    Device* getDeviceInfo(){ return deviceInfo; }
    bool getPower(){ return power; }
};

class Television : public Remocon {
    int channel;
    int volume;
public:
    Television();
    void func_W();//채널UP
    void func_A();//볼륨DOWN
    void func_D();//볼륨UP
    void func_X();//채널DOWN
    void func_C();
};

class AirConditional : public Remocon {
    int temperature;
    int power;
public:
    void func_W();//온도UP
    void func_A();//풍량DOWN
    void func_D();//풍량UP
    void func_X();//온도DOWN
    void func_C();
};

class AirCleaner : public Remocon {
    void func_W();//방향_상
    void func_A();//방향_좌 / 풍량down
    void func_D();//방향_우 / 풍량up
    void func_X();//방향_하
    void func_S();//방향 풍량 전환
    void func_C();
};

class clock : public Remocon {
    void func_W();//시간up
    void func_A();//분down
    void func_D();//분up
    void func_X();//시간down
    void func_C();
};

#endif //RTSET_H