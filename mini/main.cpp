#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

const int MAX_LEN = 4;
const string UP = "⬆";
const string DOWN = "⬇";
const string LEFT = "⬅";
const string RIGHT = "➡";
int comArr[MAX_LEN] = {0};
int userArr[MAX_LEN] = {0};
static termios orig_termios;


void printScrean(bool *, int *, int *);

int main(){
    termios new_termios;

    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~ICANON;    // non-canonical input 설정
    new_termios.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
    new_termios.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
    new_termios.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeout)
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);


    bool newYn = true;

    while(1) {
        printScrean(&newYn, comArr, userArr);
    }
    return 0;
}

void printScrean(bool *newYn, int * comArr, int * userArr) {
    char inputKey[3];
    system("clear");

    if (userArr[3] != 0) {
        *newYn = true;
        for (int j = 0; j < MAX_LEN; j++) {
            userArr[j] = 0;
        }
    }

    for (int i = 0; i < MAX_LEN; i++) {
        if (userArr[i] != 0) {
            if (comArr[i] != userArr[i]) {
                *newYn = true;
                for (int j = 0; j < MAX_LEN; j++) {
                    userArr[j] = 0;
                }
                break;
            }
        }
    }

    if (*newYn) {
        for (int i = 0; i < MAX_LEN; i++){
            int randomArrow = rand() % 4 + 1;
            comArr[i] = randomArrow;
        }
        *newYn = false;
    }
    cout << "-----------------" << endl;

    for (int i = 0; i < MAX_LEN; i++){
        switch (comArr[i]) {
            case 1:
                cout << UP << "  ";
            break;
            case 2:
                cout << DOWN << "  ";
            break;
            case 3:
                cout << LEFT << "  ";
            break;
            case 4:
                cout << RIGHT << "  ";
            break;
        }
    }
    printf("\n");
    for (int i = 0; i < MAX_LEN; i++){
        switch (userArr[i]) {
            case 1:
                cout << UP << "  ";
            break;
            case 2:
                cout << DOWN << "  ";
            break;
            case 3:
                cout << LEFT << "  ";
            break;
            case 4:
                cout << RIGHT << "  ";
            break;
        }
    }
    printf("\n");
    cout << "-----------------" << endl;

    read(0, &inputKey, sizeof(inputKey));
    for (int i = 0; i < MAX_LEN; i++) {
        if (userArr[i] == 0){
            if (inputKey[0] == 27 && inputKey[1] == 91) {
                if (inputKey[2] == 65) {
                    userArr[i] = 1;
                }else if (inputKey[2] == 66) {
                    userArr[i] = 2;
                }else if (inputKey[2] == 67) {
                    userArr[i] = 4;
                }else if (inputKey[2] == 68) {
                    userArr[i] = 3;
                }else {
                    cout << "잘못된 입력입니다." << endl;
                }
            }
            return;
        }
    }
}