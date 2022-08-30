#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> score;
vector<int> order(5,0);
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first; // 내림차순 정렬
}

int scoreTotal() {
    int total = 0;
    for (int i = 0; i < 5; i++){
        total += score[i].first;
        order[i] = score[i].second;
    }
    sort(order.begin(), order.end());

    return total;
}

int main() {
    int num = 0;

    score.assign(8, pair<int, int>(0, 0));

    //입력 받기
    for (int i = 0; i < 8; i++) {
        int input;
        cin >> input;
        score[i].first = input;
        score[i].second = i + 1;
    }

    sort(score.begin(), score.end(), cmp); //내림차순 정렬
    num = scoreTotal();

    //결과 출력
    cout << num << '\n';
    for (int i = 0; i < 5; i++) {
        cout << order[i] << ' ';
    }

    return 0;
}
