#ifndef TESTHEADER_H
#define TESTHEADER_H
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <csignal>
#include <unistd.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
using namespace std;


void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);

    // 구분자가 발견될 때까지 반복
    while(end != string::npos) {
        // start부터 end까지 부분 문자열을 추출하여 result에 추가
        result.push_back(input.substr(start, end - start));

        // start를 다음 부분으로 이동
        start = end + delimiter.size();

        // 다음 구분자 위치를 찾음
        end = input.find(delimiter, start);
    }

    // 마지막 부분 문자열을 result에 추가
    result.push_back(input.substr(start));
    return result;
}

struct test{
    int a;
    string b;
    string c;
    test(){}
    test(int a,char *b,char *c) : a(a), b(b), c(c){}
    string serializeData(){
        return to_string(a) + "^%^" + b + "^%^" + c;
    }
    void deserializeData(string s){
        cout << "1 : " << split(s, "^%^")[0] << endl;
        cout << "2 : " << split(s, "^%^")[1] << endl;
        cout << "3 : " << split(s, "^%^")[2] << endl;
    }
};

#endif //TESTHEADER_H
