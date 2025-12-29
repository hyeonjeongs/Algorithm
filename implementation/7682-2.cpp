#include <iostream>
#include <vector>

using namespace std;
int xCount= 0, oCount = 0;
int xDic= 0, oDic = 0;
void strCount(string str) {

    for (int i=0; i<str.length(); i++) {
        if (str[i]=='O') {
            oCount++;
        } else if (str[i] == 'X') {
            xCount++;
        }
    }

}

void dictacktoCount(string str) {

    for (int i=0; i<3; i++) {
        if (str[i] == str[i+3] && str[i+3] == str[i+6]) {
            if (str[i] == 'X') {
                xDic++;
            } else if (str[i] == 'O') {
                oDic++;
            }
        }
    }

    for (int i=0; i<=6; i+=3) {
        if (str[i] == str[i+1] && str[i+1] == str[i+2]) {
            if (str[i] == 'X') {
                xDic++;
            } else if (str[i] == 'O') {
                oDic++;
            }
        }
    }
    if (str[0] == str[4] && str[4] == str[8]) {
        if (str[0] == 'X') {
            xDic++;
        } else if (str[0] == 'O') {
            oDic++;
        }
    }
    if (str[2] == str[4] && str[4] == str[6]) {
        if (str[2] == 'X') {
            xDic++;
        } else if (str[2] == 'O') {
            oDic++;
        }
    }
}


int main() {

    string input;

    while (1) {
        cin >> input;
        if (input == "end") {
            break;
        }
        xCount = 0; oCount = 0;
        xDic= 0; oDic = 0;

        strCount(input);
        dictacktoCount(input);

        bool result = false;
        if (xCount == oCount+1 && xDic>0 && oDic==0) {
            result = true;
        }
        if (xCount== oCount && xDic==0 && oDic>0) {
            result = true;
        }
        if (xCount==5 && oCount==4 && xDic==0 && oDic==0) {
            result = true;
        }
        if (result) {
            cout << "valid" << '\n';
        } else {
            cout << "invalid" << '\n';
        }
    }
    return 0;
}