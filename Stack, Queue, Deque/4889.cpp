#include <iostream>
#include <stack>

using namespace std;

stack<char> stableInput(string input) {
    stack<char> st;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '}' && !st.empty() && st.top() == '{') {
            st.pop();
        } else{
            st.push(input[i]);
        }
    }

    return st;
}

int stableString(stack<char> st) {
    int cnt = 0;

    while (!st.empty()) {
        if (st.top() == '{') {
            cnt++;
            st.pop();
            if (st.top() == '{')
                st.pop();
            else { //또 괄호 바꿔야 짝맞음
                cnt++;
                st.pop();
            }
            
        } else {
            st.pop();
            if (st.top() == '}') { // 괄호 한번더 변경
                cnt++;
                st.pop();
            } else {
                st.pop();
            }
        }
    }
    return cnt;
}

int main() {
    string input;
    int i = 0;

    while (1) {
        cin >> input;
        if (input[0] == '-')
            break;

        //연산
        stack<char> st = stableInput(input); // 제거할 수 있는거 제거하기
        int result = stableString(st); // 안정적으로 바꾸는 최소 연산 수

        //출력
        cout << ++i << ". " << result << '\n';
    }

    return 0;
}