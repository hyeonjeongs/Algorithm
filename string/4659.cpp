#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 *  모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
 */

bool checkTrunc(string str) {
    vector<int> alpha(26,0);
    int current = -1; // 0 모음, 1 자음
    int num = 0;

    for(int i=0; i<str.size(); i++){
        int n = int(str[i]-97);
        alpha[n]++;

        if(n==0 || n==4 || n==8 || n==14 || n==20) {
            if(current ==0) {
                num++;
            } else {
                current =0;
                num =1;
            }
        } else {
            if(current == 1) {
                num++;
            } else {
                current = 1;
                num =1;
            }
        }

        if(num>=3) {
            return false;
        }

        // 연속 같은 글자 확인
        if(i>0 && str[i] == str[i-1]) {
            if(int(str[i]-97)==4 ||int(str[i]-97)==14) {
                continue;
            }
            return false;
        }

    }
    if(alpha[0]==0 && alpha[4]==0 && alpha[8]==0 && alpha[14]==0 && alpha[20]==0) {
        return false;
    }

    return true;
}

int main() {
    string input;

    while(true) {
        cin >> input;

        if(input == "end") {
            break;
        }

        if(checkTrunc(input)) {
            cout<<'<' <<input<< '>' << " is acceptable."<< '\n';
        } else {
            cout<<'<' <<input<< '>' << " is not acceptable."<< '\n';
        }

    }
    return 0;
}