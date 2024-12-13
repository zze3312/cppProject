#include "Remocon.h"

Remocon::Remocon() {
    deviceInfo = new Device();
    char input;
    cout << "----------기기등록----------" << endl;
    cout << "등록하실 장소를 선택해 주세요" << endl;
    cout << "1. 거실" << endl;
    cout << "2. 안방" << endl;
    cout << "3. 작은방" << endl;
    cout << "--------------------------" << endl;
    while (true) {
        cout << "입력 : "; cin >> input;
        if (input == '1') {
            this->deviceInfo->position = "거실";
            break;
        }else if (input == '2') {
            this->deviceInfo->position = "안방";
            break;
        }else if (input == '3') {
            this->deviceInfo->position = "작은방";
            break;
        }else {
            cout << "잘못된 입력입니다." << endl;
        }
    }
    cout << "--------------------------" << endl;
    cout << "등록하실 기기를 선택해 주세요" << endl;
    cout << "1. TV" << endl;
    cout << "2. 에어컨" << endl;
    cout << "3. 공기청정기" << endl;
    cout << "4. 시계" << endl;
    cout << "5. 전등" << endl;
    cout << "--------------------------" << endl;
    while (true) {
        cout << "입력 : "; cin >> input;
        if (input == '1') {
            this->deviceInfo->type = "TV";
            break;
        }else if (input == '2') {
            this->deviceInfo->type = "에어컨";
            break;
        }else if (input == '3') {
            this->deviceInfo->type = "공기청정기";
            break;
        }else if (input == '4') {
            this->deviceInfo->type = "시계";
            break;
        }else if (input == '5') {
            this->deviceInfo->type = "전등";
            break;
        }else {
            cout << "잘못된 입력입니다." << endl;
        }
    }

    deviceList[deviceCnt++] = deviceInfo;
}

Remocon::~Remocon() {
    cout << "----------기기해제----------" << endl;
    delete deviceInfo;
}

void Remocon::showDevice() {
    cout << "----------기기목록----------" << endl;
    if (deviceCnt > 0) {
        for (int i = 0; i < deviceCnt; i++) {
            cout << i + 1 << ". " << deviceList[i] -> position << " " << deviceList[i] -> type << endl;
        }
    }else {
        cout << "등록된 기기가 없습니다." << endl;
    }
    if (deviceCnt < 10) {
        cout << "0. 기기등록" << endl;
    }
    cout << "--------------------------" << endl;
}

Television::Television() {
    volume = 10;
}

void Television::func_W() {
    channel++;
    cout << "채널을 올립니다(현재 채널 : " << channel << ")" << endl;
}

void Television::func_X() {
    channel--;
    cout << "채널을 내립니다(현재 채널 : " << channel << ")" << endl;
}

void Television::func_A() {
    volume--;
    cout << "볼륨을 내립니다(현재 볼륨 : " << volume << ")" << endl;
}

void Television::func_D() {
    volume++;
    cout << "볼륨을 올립니다(현재 볼륨 : " << volume << ")" << endl;
}

void Television::func_C() {
    cout << "현재 Tv(" << getDeviceInfo()->position << ") 상태 : " << getPower() ? "켜짐" : "꺼짐" << endl;
    cout << "현재 채널 : " << channel << endl;
    cout << "현재 볼륨 : " << volume << endl;
}

void AirConditional::func_W() {
    temperature++;
    cout << "온도를 올립니다" << endl;
}
void AirConditional::func_X() {
    temperature--;
    cout << "온도를 내립니다" << endl;
}
void AirConditional::func_D() {
    power++;
    cout << "풍량을 올립니다" << endl;
}
void AirConditional::func_A() {
    power--;
    cout << "풍량을 내립니다" << endl;
}
void AirConditional::func_C() {
    cout << "현재 에어컨(" << getDeviceInfo()->position << ") 상태 : " << getPower() ? "켜짐" : "꺼짐" << endl;
    cout << "현재 온도 : " << temperature << endl;
    cout << "현재 풍량 : " << power << endl;
}