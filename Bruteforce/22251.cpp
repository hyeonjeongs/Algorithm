#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, k, p, x;
vector<vector<bool>> led;
vector<int> floors;

bool dfs(int index, int cnt, int i, vector<bool> change) {
    if (cnt == p || index ==k) {
        return false;
    }

    int num = 0;
    for (int m = 0; m < 10; m++) {
        for (int n = 0; n < 7; n++) {
            if (m == floors[i]) {
                continue;
            }
            if (change[n] != led[m][n]) {
                break;
            }
            num++;

        }
        if (num == 7) {
            return true;

        }
    }

}

int main() {

    cin >> n >> k >> p >> x;
    led.push_back({1, 1, 1, 1, 1, 1, 0});
    led.push_back({0, 1, 1, 0, 0, 0, 0});
    led.push_back({1, 1, 0, 1, 1, 0, 1});
    led.push_back({1, 1, 1, 1, 0, 0, 1});
    led.push_back({0, 1, 1, 0, 0, 1, 1});
    led.push_back({1, 0, 1, 1, 0, 1, 1});
    led.push_back({1, 0, 1, 1, 1, 1, 1});
    led.push_back({1, 1, 1, 0, 0, 0, 0});
    led.push_back({1, 1, 1, 1, 1, 1, 1});
    led.push_back({1, 1, 1, 1, 0, 1, 1});

    string floor_str = to_string(x); // 현재 층수
    // 현재 층수 vector로 변환

    for (int i = 0; i < k; i++) {
        floors.push_back(floor_str[i] - '0'); // 현재 층수
    }

    int cnt = 0;
    int result = 0;


    vector<vector<int>> change_cnt(k);

    // 바꾼 수가 n보다 작은 경우만 가능하도
    // 비교할 때 비트마스킹으로 두개 비교해서
    int index = 1;
    for (int j = 0; j < 10; j++) {
        vector<bool> current = led[floors[j]]; // 그 자리 수의 현재 인덱스들
        vector<bool> change = current;
        for(int i=0; i<7; i++) {
            int num =0;
            change[i] = !change[i];
            cnt = dfs(index, cnt, i, change);
        }
    }

    return 0;
}