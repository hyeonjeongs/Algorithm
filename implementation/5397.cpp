#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string stackToString(stack<char> &left, stack<char> &right) {
    string pwd;
    while (!left.empty()) { //왼쪽꺼 오른쪽에 저장해서 순서대로 저장할 수 있도록 하기
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        pwd += right.top();
        right.pop();
    }
    return pwd;
}

string findPassword(string s) {
    stack<char> left;
    stack<char> right;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '-':
                if (!left.empty())
                    left.pop();
                break;
            case '>':
                if (!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
                break;
            case '<':
                if (!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
                break;
            default:
                left.push(s[i]); // 커서 왼쪽에 삽입됨
        }
    }
    string pwd = stackToString(left, right);
    return pwd;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << findPassword(s) << '\n';
    }
    return 0;
}