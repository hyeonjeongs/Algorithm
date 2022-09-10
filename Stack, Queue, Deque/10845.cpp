#include<iostream>
#include<queue>

using namespace std;

queue<int> que;

void push() {
    int num;
    cin >> num;
    que.push(num);
}

void pop() {
    if (que.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << que.front() << '\n';
        que.pop();
    }
}

void size() {
    cout << que.size()<<'\n';
}

void empty() {
    if (que.empty()) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

void front() {
    if (que.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << que.front() << '\n';
    }
}

void back() {
    if (que.empty()) {
        cout << -1 << '\n';
    }
    else {
        cout << que.back() << '\n';
    }
}
int main() {
    int n;
    cin >> n;
    string str;

    while (n--) {
        cin >> str;
        if (str == "push") {
            push();
        }
        else if (str == "pop") {
            pop();
        }
        else if (str == "size") {
            size();
        }
        else if (str == "empty") {
            empty();
        }
        else if (str == "front") {
            front();
        }
        else if (str == "back") {
            back();
        }
    }

    return 0;
}