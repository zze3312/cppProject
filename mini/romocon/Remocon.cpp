#include "Remocon.h"

Remocon::Remocon() {
    power = false;
    remoconMode = false;
    timeModeYn = false;
}

void Remocon::func_R(){
    power = !power;
    cout << "전원이 " << (power ? "켜" : "꺼") << "졌습니다." <<endl;
}

void Remocon::func_T(){
    timeModeYn = timeModeYn;
    cout << "취침모드 설정이 " << (timeModeYn ? "켜" : "꺼") << "졌습니다." <<endl;
}

void Remocon::func_S(){
    remoconMode = remoconMode;
    cout << "취침 시간설정 모드가 " << (remoconMode ? "켜" : "꺼") << "졌습니다" <<endl;
}



Television::Television() {
    volume = 10;
    channel = 1;
}

void Television::func_W() {
    if(timeModeYn){
        timeModeTime->tm_hour++;
    }else{
        channel++;
        cout << "채널을 올립니다(현재 채널 : " << channel << ")" << endl;
    }
    
}

void Television::func_X() {
    if(timeModeYn){
        timeModeTime->tm_hour--;
    }else{
        channel--;
        cout << "채널을 내립니다(현재 채널 : " << channel << ")" << endl;
    }
}

void Television::func_A() {
    if(timeModeYn){
        timeModeTime->tm_min--;
    }else{
        volume--;
        cout << "볼륨을 내립니다(현재 볼륨 : " << volume << ")" << endl;
    }
}

void Television::func_D() {
    if(timeModeYn){
        timeModeTime->tm_min++;
    }else{
        volume++;
        cout << "볼륨을 올립니다(현재 볼륨 : " << volume << ")" << endl;
    }
}


void AirConditional::func_W() {
    if(timeModeYn){
        timeModeTime->tm_hour++;
    }else{
        temperature++;
        cout << "온도를 올립니다" << endl;
    }
}

void AirConditional::func_X() {
    if(timeModeYn){
        timeModeTime->tm_hour--;
    }else{
        temperature--;
        cout << "온도를 내립니다" << endl;
    }
}

void AirConditional::func_D() {
    if(timeModeYn){
        timeModeTime->tm_min ++;
    }else{
        airflow++;
        cout << "풍량을 올립니다" << endl;
    }
}

void AirConditional::func_A() {
    if(timeModeYn){
        timeModeTime->tm_min--;
    }else{
        airflow--;
        cout << "풍량을 내립니다" << endl;
    }
}


void AirCleaner::func_W(){
    if(timeModeYn){
        timeModeTime->tm_hour++;
    }else{
        direction = 'u';
        cout << "방향을 위쪽으로 바꿨습니다" << endl;
    }
}

void AirCleaner::func_X(){
    if(timeModeYn){
        timeModeTime->tm_hour--;
    }else{
        direction = 'd';
        cout << "방향을 아래쪽으로 바꿨습니다" << endl;
    }
}

void AirCleaner::func_D() {
    if(timeModeYn){
        timeModeTime->tm_min ++;
    }else{
        airflow++;
        cout << "풍량을 올립니다" << endl;
    }
}

void AirCleaner::func_A() {
    if(timeModeYn){
        timeModeTime->tm_min--;
    }else{
        airflow--;
        cout << "풍량을 내립니다" << endl;
    }
}



Clock::Clock(){
    nowtime = new tm();
    time_t timer = time(NULL);
    nowtime = localtime(&timer);
}

Clock::~Clock(){
    delete nowtime;
}

void Clock::func_W(){
    if(timeModeYn){
        timeModeTime->tm_hour++;
    }else{
        nowtime->tm_hour ++;
        cout << "현재시각을 올립니다" << endl;
    }
}

void Clock::func_X(){
    if(timeModeYn){
        timeModeTime->tm_hour--;
    }else{
        nowtime->tm_hour --;
        cout << "현재시각을 내립니다" << endl;
    }
}

void Clock::func_A(){
    if(timeModeYn){
        timeModeTime->tm_min--;
    }else{
        nowtime->tm_min --;
        cout << "현재분을 내립니다" << endl;
    }
}

void Clock::func_D(){
    if(timeModeYn){
        timeModeTime->tm_min ++;
    }else{
        nowtime->tm_min ++;
        cout << "현재분을 올립니다" << endl;
    }
}

void RemoconHandler::insertDevice(){
    char num;
    char input;
    
    newDevice = new Device();
    cout << "----------기기등록----------" << endl;
    cout << "등록하실 번호를 선택해 주세요";
    cin >> input;
    if(isdigit(num)){
        cout << "--------------------------" << endl;
        cout << "등록하실 장소를 선택해 주세요" << endl;
        cout << "1. 거실" << endl;
        cout << "2. 안방" << endl;
        cout << "3. 작은방" << endl;
        cout << "--------------------------" << endl;
        while (true) {
            cout << "입력 : ";
            cin >> input;
            if (input == '1') {
                this->newDevice->position = "거실";
                cout << "거실이 선택되었습니다." << endl;
                break;
            }else if (input == '2') {
                this->newDevice->position = "안방";
                cout << "안방이 선택되었습니다." << endl;
                break;
            }else if (input == '3') {
                this->newDevice->position = "작은방";
                cout << "작은방이 선택되었습니다." << endl;
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
            cout << "입력 : "; 
            cin >> input;
            if (input == '1') {
                this->newDevice->type = "TV";
                cout << "TV가 선택되었습니다." << endl;
                break;
            }else if (input == '2') {
                this->newDevice->type = "에어컨";
                cout << "에어컨이 선택되었습니다." << endl;
                break;
            }else if (input == '3') {
                this->newDevice->type = "공기청정기";
                cout << "공기청정기가 선택되었습니다." << endl;
                break;
            }else if (input == '4') {
                this->newDevice->type = "시계";
                cout << "시계가 선택되었습니다." << endl;
                break;
            }else if (input == '5') {
                this->newDevice->type = "전등";
                cout << "전등이 선택되었습니다." << endl;
                break;
            }else {
                cout << "잘못된 입력입니다." << endl;
            }
        }
    }
    deviceList[num] = newDevice;
}

void RemoconHandler::removeDevide(){
    char input;
    Device selectDevice;

    cout << "----------기기해제----------" << endl;
    cout << "등록하실 번호를 선택해 주세요";
    cin >> input;
    if(isdigit(input)){
        delete deviceList[input];
    }
}

void RemoconHandler::showDevice() {
    system("clear");
    cout << "----------기기목록----------" << endl;
    for (int i = 0; i < deviceCnt; i++) {
        if(deviceList[i] -> position != ""){
            cout << i + 1 << ". " << deviceList[i] -> position << " " << deviceList[i] -> type << endl;
        }else{
            cout << "등록된 기기가 없습니다" << endl;
        }
        
    }
    cout << "0. 기기등록" << endl;
    cout << "--------------------------" << endl;
}