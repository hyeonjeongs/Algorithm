#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문자열 -> 숫자로 추출 하여 합 반환
int digitCmp(string str) {
    int str_size = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i]))
            str_size += str[i] - '0'; //char -> int로 변환
    }
    return str_size;
}

bool cmp(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    if (digitCmp(a) != digitCmp(b)) { //숫자 합이 다르면
        return digitCmp(a) < digitCmp(b);
    }
    return a < b; //사전순
}

int main() {
    int n;
    cin >> n;
    vector<string> guitar(n, "");

    //입력
    for (int i = 0; i < n; i++) {
        cin >> guitar[i];
    }

    sort(guitar.begin(), guitar.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << guitar[i] << '\n';
    }
    return 0;
}