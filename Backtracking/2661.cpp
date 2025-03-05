#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
string result = "";
bool checkPossible(string num){
    int cnt = num.size()/2;
    int index = num.size();

    for(int i=1; i<=cnt; i++) {
        string back = num.substr(index-i,i);
        string front = num.substr(index-(i*2), i);
        if(back==front) {
            return false;
        }
    }
    return true;
}

void backtracking(string num){
    if(result != "") {
        return;
    }
    if(!checkPossible(num)) {
        return;
    }
    if(num.size() == n) {
        result = num;
        return;
    }

    for(int i=1; i<=3; i++) {
        char ch = i + '0';
        backtracking(num+ ch);
    }
}
int main() {
    cin >> n;
    // 현재 인덱스 기준으로 substr로 잘라서 string이 같은지 확인, 이때 n/2까지 진행

    for(int i=1; i<=3; i++) {
        backtracking(to_string(i));
    }

    cout << result << '\n';

    return 0;
}