#include <iostream>
#include <vector>
#include <set>

using namespace std;
string str;
set<string> s;

void makeNum(int left, int right, string path) {
    // 더 이상 좌우로 이동할 곳이 없을 경우
    if (left == 0 && right == str.length() - 1) { //기저조건
        s.insert(path); //현재 숫자를 set에 넣기(중복 제거해줌)
        return;
    }

    if (left > 0) { //왼쪽에 값 넣기
        // 왼쪽에 숫자를 하나 적는 과정
        makeNum(left - 1, right, path + str[left - 1] + path); //왼쪽에 있는 값 path에 전달
    }
    if (right < str.length() - 1) { //오른쪽으로 이동
        // 오른쪽에 숫자를 하나 적는 과정
        makeNum(left, right + 1, path + path + str[right + 1]); //오른쪽에 있는 값 전달
    }
}

int main() {
    //입력
    cin >> str;

    // 계산
    for (int i = 0; i < str.length(); i++) {
        // str[i]를 string 형태로 바꾸기 위해 tmp를 더함
        string tmp = ""; //그냥 str[i]는 char이니까
        makeNum(i, i, tmp + str[i]); //숫자 만들기
    }

    cout << s.size(); //출력

    return 0;
}