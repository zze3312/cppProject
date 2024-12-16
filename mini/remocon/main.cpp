#include <iostream>
#include "Remocon.h"

int main(){
    Device *deviceList[10];
    Remocon *remoconList[10];
    for (int i = 0; i < 10; i++) {
        deviceList[i] = new Device;
    }

    RemoconHandler rhdr;
    char input;

    while (true) {
        rhdr.showDevice(deviceList);
        cin >> input;
        if (input == '0') {
            rhdr.insertDevice(deviceList, remoconList);
        }else {
            if (deviceList[input - '0' - 1]->type != "")
                remoconList[input - '0' - 1]->funcRemocon();
            else
                cout << "기기를 등록해 주세요" << endl;
        }
    }
}