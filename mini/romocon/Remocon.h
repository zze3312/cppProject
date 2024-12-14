#ifndef RTSET_H
#define RTSET_H

#include <iostream>

using namespace std;

struct Device {
    string position; //기기장소
    string type; //기기종류
};

class Remocon {
protected:
    bool power;
    bool remoconMode;
    bool timeModeYn;
    tm *nowtime;
    tm *timeModeTime = new tm();
public:
    Remocon();
    void func_R(); //전원버튼
    void func_T(); //취침모드 전환
    void func_S(); //취침시간 설정모드 전환
    virtual void func_W(); //UP1
    virtual void func_A(); //DOWN2
    virtual void func_D(); //UP2
    virtual void func_X(); //DOWN1
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
};

class AirConditional : public Remocon {
    int temperature;
    int airflow;
public:
    void func_W();//온도UP
    void func_A();//풍량DOWN
    void func_D();//풍량UP
    void func_X();//온도DOWN
};

class AirCleaner : public Remocon {
    char direction;
    int airflow;
public:
    void func_W();//방향_상
    void func_X();//방향_하
    void func_D();//풍량up
    void func_A();//풍량down
};

class Clock : public Remocon {
public:
    Clock();
    ~Clock();
    void func_W();//시간up
    void func_X();//시간down
    void func_D();//분up
    void func_A();//분down
};

class Light : public Remocon{

};

class RemoconHandler {
    Device *newDevice;
    static Device *deviceList[10];
    static int deviceCnt;
public:
    void insertDevice();
    void removeDevide();
    void showDevice(); //기기목록
};

#endif //RTSET_H