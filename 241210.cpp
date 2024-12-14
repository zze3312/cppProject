#include <iostream>

using namespace std;
struct user {
    string userName;
    int userGold;
    string userItems[3];
};

class Inventory {
    user *invenUser;
public:
    Inventory(string inputUserName) {
        invenUser = new user(); //동적할당을 통한 메모리 확보
        invenUser->userName = inputUserName;
        //사용자 골드와 아이템을 텍스트파일에서 불러오는 프로세스 등
        invenUser->userGold = 10000;
        invenUser->userItems[0] = "간식";
        invenUser->userItems[1] = "밥";
        invenUser->userItems[2] = "책";

        cout << invenUser->userName <<"의 가방이 열렸습니다" << endl;
    };
    ~Inventory() {
        cout << invenUser->userName << "의 가방이 닫혔습니다" << endl;
        //변경된 사용자 골드와 아이템 정보를 텍스트파일에 저장하는 프로세스 등
        delete invenUser; //동적할당 받았던 메모리 반환
    }
    explicit Inventory(Inventory &input) : invenUser(input.invenUser) {
        cout << "복사생성자 실행!!!" << endl;
    }

    void useGold(int gold) {
        cout << gold <<" 골드를 사용합니다" << endl;
        this -> invenUser -> userGold -= gold;
    }

    void discardItem(int idx) {
        cout << idx << "칸에 있는 아이템을 버립니다" << endl;
        invenUser->userItems[idx] = "";
    }

    void printMyInventory() {
        cout << "<<" << invenUser->userName << "의 소지품확인>>" << endl;
        cout << "골드 : " << invenUser->userGold << endl;
        for (int i = 0; i < 3; i++) {
            cout << i << "번 칸에 있는 아이템 : " << invenUser->userItems[i] << endl;
        }
        cout << "<<" << invenUser->userName << "의 소지품확인 끝>>" << endl;
    }
};

int main(){
    Inventory myInven("kong");
    cout << endl;
    Inventory myInven2 = myInven;
    cout << endl << endl;

    myInven.printMyInventory();
    cout << endl;
    myInven2.printMyInventory();
    cout << endl << endl;

    return 0;
}
