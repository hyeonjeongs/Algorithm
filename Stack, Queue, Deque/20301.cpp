#include<iostream>
#include<deque>

using namespace std;

deque<int> deq;

void forword(int k) {
    for (int i = 0; i < k - 1; i++) {
        deq.push_back(deq.front());
        deq.pop_front();
    }
    cout << deq.front() << "\n";
    deq.pop_front();
}

void reverse(int k) {
    for (int i = 0; i < k - 1; i++) {
        deq.push_front(deq.back());
        deq.pop_back();
    }
    cout << deq.back() << "\n";
    deq.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, m;
    int changeNum=0;
    bool change = false;
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        deq.push_back(i + 1);
    }

    while (!deq.empty()) {
        if (!change) {
            forword(k);
        }
        else if (change) {
            reverse(k);
        }

        changeNum++;
        if (changeNum == m) {
            changeNum = 0;
            change = !change;
        }
    }

    return 0;
}