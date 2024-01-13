#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
map<int, int> recommendNum;

bool cpm(pi a, pi b) {
    return a.first<b.first;
}

void recommendPresident(int n, int input, vector<pi> &recommend, int current_index) {
    int cnt = 987654321, order=987654321, index=-1;

    if (recommendNum.find(input) != recommendNum.end()) {
        recommendNum[input]++;
        return;
    }

    if (recommend.size() < n) {
        recommend.push_back(pi(input, current_index)); // 학생숫자, 순서
        recommendNum[input] = 1; // 추천받은 횟수
        return;
    }

    // 빈자리 없고 추천수 가장 적은거 판단
    for (int i = 0; i < n; i++) {
        if(recommendNum[recommend[i].first] < cnt) {
            cnt = recommendNum[recommend[i].first];
        }
    }

    // 추천수 가장 적은것들중 가장 오래된것 판단
    for (int i = 0; i < n; i++) {
        if (recommendNum[recommend[i].first] == cnt && recommend[i].second<order) { // 추천수 같은경우 & 오래된경우
            order = recommend[i].second;
            index = i;
        }
    }

    recommendNum.erase(recommend[index].first);
    recommend[index].first = input;
    recommend[index].second = current_index;
    recommendNum[input]=1;
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<pi> recommend;

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        recommendPresident(n, input, recommend,i);
    }

    sort(recommend.begin(), recommend.end(), cpm);
    for (int i = 0; i < recommend.size(); i++) {
        cout << recommend[i].first << ' ';
    }

    return 0;
}