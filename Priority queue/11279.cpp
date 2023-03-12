#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void solve(int input, priority_queue<int, vector<int>>& pq) {
    if (input == 0) {
        if (pq.empty()) //빈경우 처리
            cout << 0 << '\n';
        else {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
    else if (input > 0) {
        pq.push(input);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    priority_queue<int, vector<int>> pq; //우선순위 큐 사용하기

    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        solve(input, pq);
    }

    return 0;

}