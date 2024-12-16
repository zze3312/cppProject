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

void Remocon::func_W(){return;}
void Remocon::func_A(){return;}
void Remocon::func_D(){return;}
void Remocon::func_X(){return;}
void Remocon::funcRemocon(){
    char input;
    printFunc();
    cin >> input;
    switch (input) {
        case 'w': case 'W':
            func_W();
        break;
        case 'x': case 'X':
            func_X();
        break;
        case 'd': case 'D':
            func_D();
        break;
        case 'a': case 'A':
            func_A();
        break;
        case 'r': case 'R':
            func_R();
        break;
        case 't': case 'T':
            func_T();
        break;
        case 's': case 'S':
            func_S();
        break;
        default:
            cout << "잘못된 입력입니다." << endl;
    }
}

void Remocon::printFunc(){return;}


Television::Television() {
    volume = 10;
    channel = 1;
}
void Television::printFunc() {
    cout << "------------TV------------" << endl;
    cout << " w : 채널UP" << endl;
    cout << " x : 채널DOWN" << endl;
    cout << " d : 볼륨UP" << endl;
    cout << " a : 볼륨DOWN" << endl;
    cout << " r : 전원버튼" << endl;
    cout << " t : 취침모드 전환" << endl;
    cout << " s : 취침시간 설정모드 전환" << endl;
    cout << "--------------------------" << endl;
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

void AirConditional::printFunc() {
    cout << "------------TV------------" << endl;
    cout << " w : 온도UP" << endl;
    cout << " x : 온도DOWN" << endl;
    cout << " d : 풍량UP" << endl;
    cout << " a : 풍량DOWN" << endl;
    cout << " r : 전원버튼" << endl;
    cout << " t : 취침모드 전환" << endl;
    cout << " s : 취침시간 설정모드 전환" << endl;
    cout << "--------------------------" << endl;
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


void AirCleaner::printFunc() {
    cout << "------------TV------------" << endl;
    cout << " w : 방향_상" << endl;
    cout << " x : 방향_하" << endl;
    cout << " d : 풍량UP" << endl;
    cout << " a : 풍량DOWN" << endl;
    cout << " r : 전원버튼" << endl;
    cout << " t : 취침모드 전환" << endl;
    cout << " s : 취침시간 설정모드 전환" << endl;
    cout << "--------------------------" << endl;
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

void Clock::printFunc() {
    cout << "------------TV------------" << endl;
    cout << " w : 시간UP" << endl;
    cout << " x : 시간DOWN" << endl;
    cout << " d : 분UP" << endl;
    cout << " a : 분DOWN" << endl;
    cout << " r : 전원버튼" << endl;
    cout << " t : 취침모드 전환" << endl;
    cout << " s : 취침시간 설정모드 전환" << endl;
    cout << "--------------------------" << endl;
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


void Light::printFunc() {
    cout << "------------TV------------" << endl;
    cout << " r : 전원버튼" << endl;
    cout << " t : 취침모드 전환" << endl;
    cout << " s : 취침시간 설정모드 전환" << endl;
    cout << "--------------------------" << endl;
}

void RemoconHandler::insertDevice(Device *deviceList[], Remocon *remoconList[10]){
    char num;
    char input;
    
    Device *newDevice = new Device();
    system("clear");
    cout << "----------기기등록----------" << endl;
    cout << "등록하실 번호를 선택해 주세요";
    cin >> num;
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
                newDevice->position = "거실";
                cout << "거실이 선택되었습니다." << endl;
                break;
            }else if (input == '2') {
                newDevice->position = "안방";
                cout << "안방이 선택되었습니다." << endl;
                break;
            }else if (input == '3') {
                newDevice->position = "작은방";
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
                newDevice->type = "TV";
                cout << "TV가 선택되었습니다." << endl;
                break;
            }else if (input == '2') {
                newDevice->type = "에어컨";
                cout << "에어컨이 선택되었습니다." << endl;
                break;
            }else if (input == '3') {
                newDevice->type = "공기청정기";
                cout << "공기청정기가 선택되었습니다." << endl;
                break;
            }else if (input == '4') {
                newDevice->type = "시계";
                cout << "시계가 선택되었습니다." << endl;
                break;
            }else if (input == '5') {
                newDevice->type = "전등";
                cout << "전등이 선택되었습니다." << endl;
                break;
            }else {
                cout << "잘못된 입력입니다." << endl;
            }
        }
    }
    deviceList[num - '0' - 1]->position = newDevice->position;
    deviceList[num - '0' - 1]->type = newDevice->type;
    if (newDevice->type == "TV") {
        remoconList[num - '0' - 1] = new Television();
    }else if (newDevice->type == "에어컨") {
        remoconList[num - '0' - 1] = new AirConditional();
    }else if (newDevice->type == "공기청정기") {
        remoconList[num - '0' - 1] = new AirCleaner();
    }else if (newDevice->type == "시계") {
        remoconList[num - '0' - 1] = new Clock();
    }else if (newDevice->type == "전등") {
        remoconList[num - '0' - 1] = new Light();
    }

}

void RemoconHandler::removeDevide(Device *deviceList[]){
    char input;
    Device selectDevice;

    cout << "----------기기해제----------" << endl;
    cout << "등록하실 번호를 선택해 주세요";
    cin >> input;
    if(isdigit(input)){
        delete deviceList[input];
    }
}

void RemoconHandler::showDevice(Device *deviceList[]) {
    system("clear");
    cout << "----------기기목록----------" << endl;
    for (int i = 0; i < 10; i++) {
        if(deviceList[i]->position != ""){
            cout << i + 1 << ". " << deviceList[i]->position << " " << deviceList[i]->type << endl;
        }else{
            cout << i + 1 << ". 등록된 기기가 없습니다" << endl;
        }
        
    }
    cout << "--------------------------" << endl;
    cout << "0. 기기등록" << endl;
    cout << "--------------------------" << endl;
}