#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int r, c, k;
int arr[101][101];

bool cmp(pi a, pi b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int sortRow(int index, int col) {

    int i = 1;
    int num[101]; // counts 어디 인덱스에 있는지 체크
    memset(num, -1, sizeof(num));
    vector<pi> counts;
    for(int j=1; j<=col; j++) {
        int current = arr[index][j];
        if(current == 0) continue;
        if(num[current]<0) {
            num[current] = counts.size();
            counts.push_back(pi(current, 1));
        } else {
            counts[num[current]].second++;
        }
    }

    sort(counts.begin(), counts.end(), cmp);
    i=1;
    for(int j=0; j<counts.size(); j++) {
        arr[index][i] = counts[j].first;
        arr[index][i+1] = counts[j].second;
        i+=2;
        if(i>=100) {
            break;
        }
    }
    for(int j=i; j<=100; j++) { // 초기화
        arr[index][j] = 0;
    }
    return counts.size()*2;
}

int sortCol(int index, int row) {
    int i = 1;
    int num[101]; // counts 어디 인덱스에 있는지 체크
    memset(num, -1, sizeof(num));
    vector<pi> counts;
    for(int j=1; j<=row; j++) {
        int current= arr[j][index];
        if(current == 0) continue; // 여기 안해서 틀림 (0인경우 무시)
        if(num[current]<0) {
            num[current] = counts.size();
            counts.push_back(pi(current, 1));
        } else {
            counts[num[current]].second++;
        }
    }

    sort(counts.begin(), counts.end(), cmp);
    i=1;
    for(int j=0; j<counts.size(); j++) {
        arr[i][index] = counts[j].first;
        arr[i+1][index] = counts[j].second;
        i+=2;
        if(i>=100) {
            break;
        }
    }
    for(int j=i; j<=100; j++) { // 초기화 (이부분 안해줬음)
        arr[j][index] = 0;
    }
    return counts.size()*2;
}

int makeNum() {

    int r_cnt = 3, c_cnt = 3;
    int cnt = 0;
    while(cnt<=100) {
        if(arr[r][c] == k) {
            return cnt;
        }

        cnt++;

        int current_cnt= 0;
        if(r_cnt>= c_cnt) {
            for(int i=1; i<= r_cnt; i++) {
                current_cnt = max(current_cnt, sortRow(i, c_cnt));
            }
            c_cnt = current_cnt;
        } else {
            for(int i=1; i<= c_cnt; i++) {
                current_cnt = max(current_cnt, sortCol(i, r_cnt));
            }
            r_cnt = current_cnt;
        }
    }
    return cnt;
}
int main() {

    cin >> r >> c >> k;
    memset(arr, 0, sizeof(arr));

    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }

    int result = makeNum();
    if(result == 101) {
        result = -1;
    }

    cout << result << '\n';

    return 0;
}