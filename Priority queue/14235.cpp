/*
 * 착한 아이들을 만날 때마다 자신이 들고있는 가장 가치가 큰 선물 하나를 선물해 줄 것이다. -> 우선순위큐 쓰는이유
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void givePresent(priority_queue<int, vector<int>>& pq) {
    if(pq.empty()) {
        cout<< -1<<'\n';
        return;
    }
    cout<< pq.top() <<'\n';
    pq.pop();
}

void getPresent(priority_queue<int, vector<int>>& pq, int n) {
    for(int i=0; i<n; i++) {
        int input;
        cin>> input;
        pq.push(input);
    }
}

void solve(int n, priority_queue<int, vector<int>>& pq) {
    int input;
    for(int i=0; i<n; i++) {
        cin>>input;
        if(input == 0) {
            givePresent(pq);
        }
        if(input != 0) {
            getPresent(pq, input);
        }
    }
}

int main(){
    int n;
    priority_queue<int, vector<int>> pq;
    cin>>n;

    solve(n, pq);

    return 0;
}