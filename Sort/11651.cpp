#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> arr;

// 오름차순 정렬
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back(pair<int,int>(x,y));
    }

    //사용자 정의 함수 정렬
    sort(arr.begin(), arr.end(),cmp);


    // 출력
    for (int i = 0; i < num; i++) {
        cout << arr[i].first << ' ' << arr[i].second<<'\n';
    }
}