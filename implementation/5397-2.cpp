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


string findPassword(string str) {
    stack<char> left;
    stack<char> right;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<') {
            if (!left.empty()) {
                int num = left.top();
                left.pop();
                right.push(num);
            }
        } else if (str[i] == '>') {
            if (!right.empty()) {
                int num = right.top();
                right.pop();
                left.push(num);
            }

        } else if (str[i] == '-') {
            if (!left.empty()) {
                left.pop();
            }
        } else {
            left.push(str[i]);
        }
    }
    string pwd = stackToString(left, right);
    return pwd;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string input;
        cin >> input;
        cout<<findPassword(input)<<'\n';
    }


    return 0;
}