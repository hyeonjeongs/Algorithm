#include <iostream>
#include <queue>

using namespace std;

// 상자에 자신이원하는 수보다 적은개수있으면 선물가져가지 못함
// 선물상자에서 pop하면 다시 우선순위 큐에 넣어서 최대힙 만들기
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; // 선물 상자의 수, 아이들의 수
    priority_queue<int, vector<int>> max_pq; // 최대힙 만들기
    // 입력
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        max_pq.push(input);
    }

    for (int i = 0; i < m; i++) {
        int input, max_top, pq_pop;
        cin >> input;
        max_top = max_pq.top(); //가장 큰 값 저장
        if (max_top < input) {
            cout << 0;
            return 0;
        }
        // 위에 있는 값 꺼내고, 꺼낸 값 빼서 다시 저장
        max_top -= input;
        max_pq.pop();
        max_pq.push(max_top);
    }

    cout << 1;
    return 0;
}
