#include <iostream>
#include <cstring>
using namespace std;

class baseControl {

public:
    baseControl() : powerOnOff(false), offTimeYn(false), offTime("") {}
    void onOff(){
        powerOnOff = !powerOnOff;
    }
    string getOffTime() {
        return offTime;
    }
    bool getPowerOnOff() {
        return powerOnOff;
    }
    void setPosition(string position) {
        this->position = position;
    }
    string getPosition() {
        return position;
    }
    void setOffTime(){
        int hour, min;
        cout << "시간을 입력해 주세요."; cin >> hour;
        cout << "분을 입력해 주세요."; cin >> min;

        offTimeYn = true;
        offTime = to_string(hour) + ":" + to_string(min);
        cout << "취침시간이 " << offTime << "으로 설정되었습니다" << endl;
    }
    virtual void printStatus() {return;}
};

class clock : public baseControl {
    int hours;
    int minutes;
    bool alarmYn;
    string alarmTime;
protected:
    string nowTime;
public:
    clock(string position) : baseControl(), alarmYn(false), alarmTime("") {
        setPosition(position);
        time_t now = time(NULL);
        tm *local = localtime(&now);
        hours(local->tm_hour), minutes(local->tm_min);
    }
    clock(clock &copy) : baseControl(), hours(copy.hours), minutes(copy.minutes), alarmYn(copy.alarmYn), alarmTime(copy.alarmTime) { };

    void setAlarm() {
        cout << "시간을 입력하세요 : "; cin >> hours;
        cout << "분을 입력하세요 : "; cin >> minutes;

        cout << "시계의 알람 시간이 " << hours << ":" << minutes << "으로 설정되었습니다." << endl;

        alarmTime = to_string(hours) + ":" + to_string(minutes);
    }
    void setMin() {
        cout << "분을 입력해주세요 : "; cin >> minutes;

        nowTime = to_string(hours) + ":" + to_string(minutes);
    }
    void setHour() {
        cout << "시간을 입력해주세요 : "; cin >> hours;

        nowTime = to_string(hours) + ":" + to_string(minutes);
    }
    void printStatus() {
        cout << "현재시간은 " << hours << ":" << minutes << ":" << "입니다." << endl;
        cout << "알람설정 : " << alarmYn ? "켜짐" : "꺼짐" << endl;
        if (alarmYn) {
            cout << "설정된 알람 시간 : " << alarmTime << endl;
        }
    }
    virtual void checkOffTime() {
        return;
    }
};

class airCleaner : public clock {
    char direction;
    int power;
public:
    airCleaner(string position) : clock(position), direction('c'), power(0) {
        setPosition(position);
    }
    void directionUp() {
        direction = 'u';
        cout << "방향을 위쪽으로 바꿨습니다" << endl;
    }
    void directionDown() {
        direction = 'd';
        cout << "방향을 아래쪽으로 바꿨습니다" << endl;
    }
    void directionLeft() {
        direction = 'l';
        cout << "방향을 왼쪽으로 바꿨습니다" << endl;
    }
    void directionRight() {
        direction = 'r';
        cout << "방향을 오른쪽으로 바꿨습니다" << endl;
    }
    void directionCenter() {
        direction = 'c';
        cout << "방향을 중앙으로 바꿨습니다" << endl;
    }
    void increasePower() {
        power++;
        cout << "풍량을 올립니다" << endl;
    }
    void decreasePower() {
        power--;
        cout << "풍량을 내립니다" << endl;
    }
    void checkOffTime() {
        if (getPowerOnOff()) {
            if (nowTime == getOffTime()) {
                cout << "전원이 꺼집니다" << endl;
                this -> power = 0;
                this -> onOff();
            }
        }
    }
    void printStatus() {
        cout << "현재 공기청정기(" << getPosition() << ") 상태 : " << getPowerOnOff() ? "켜짐" : "꺼짐" << endl;
        cout << "현재 방향 : ";
        if (direction == 'u') cout << "위";
        else if (direction == 'd') cout << "아래";
        else if (direction == 'l') cout << "왼쪽";
        else if (direction == 'r') cout << "오른쪽";
        else cout << "중앙";
        cout << endl;
        cout << "현재 풍량 : " << power << endl;
    }
};

class light : public clock {

public:
    light(string position) : clock(position) {
        setPosition(position);
    }
    void checkOffTime() {
        if (getPowerOnOff()) {
            if (nowTime == getOffTime()) {
                cout << "전원이 꺼집니다" << endl;
                this -> onOff();
            }
        }
    }
    void printStatus() {
        cout << "현재 전등(" << getPosition() << ") 상태 : " << getPowerOnOff() ? "켜짐" : "꺼짐" << endl;
    }
};
