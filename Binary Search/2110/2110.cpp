#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> house;
int router(int dist) {
    int cnt = 1;
    int pos = house[0];

    for (int i = 1; i < house.size(); i++) {
        if (house[i] - pos < dist) 
            continue;
        cnt++;
        pos = house[i];
    }
    return cnt; //설치된 공유기 수
}

int binarySearch(int left, int right, int c) {
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int installed = router(mid);

        if (installed < c) //거리를 줄이기
            right = mid - 1;
        else if (installed >= c) { //거리를 늘리기
            result = mid;
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, c;

    cin >> n >> c;
    house.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> house[i];

    sort(house.begin(), house.end());

    cout << binarySearch(1, house[n - 1] - house[0], c);
}