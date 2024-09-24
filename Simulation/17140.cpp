#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#define MAX 101
using namespace std;

typedef pair<int, int> pi;
vector<vector<int>> arr;
bool cmp(pi a, pi b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

// 배열에 <node, 개수> 로 입력
int makeNumber(int r, int c, int k) {

    vector<vector<pi>> data;
    int counter[MAX];

    int r_size=3;
    int c_size=3;
    int time =0;

    while(1) {

        if(arr[r][c] == k){
            return time;
        }
        if(time>100) {
            return -1;
        }

        if(r_size>=c_size) { // r 연산
            for(int i=1; i<=r_size; i++) {
                memset(counter, 0, sizeof(counter)); // 카운터
                vector<pi> part;
                for(int j=1; j<=c_size; j++) {
                    counter[arr[i][j]]++;
                }
                for(int j=1; j<MAX; j++) {
                    if(counter[j]!=0) {
                        part.push_back({j, counter[j]});
                    }
                }
                int lens = part.size();
                r_size = max(r_size, lens*2);
                sort(part.begin(), part.end(), cmp);
                int index=1;
                for(int j=0; j<lens; j++) {
                    arr[i][index++] = part[j].first;
                    arr[i][index++] = part[j].second;
                }
            }

        } else { // c 연산
            for(int j=1; j<=c_size; j++) {
                memset(counter, 0, sizeof(counter)); // 카운터
                vector<pi> part;
                for(int i=1; i<=r_size; i++) {
                    counter[arr[i][j]]++;
                }
                for(int i=1; i<MAX; i++) {
                    if(counter[i]!=0) {
                        part.push_back({i, counter[i]});
                    }
                }
                int lens = part.size();
                c_size = max(c_size, lens*2);
                sort(part.begin(), part.end(), cmp);
                int index=1;
                for(int i=0; i<lens; i++) {
                    arr[index++][j] = part[i].first;
                    arr[index++][j] = part[i].second;
                }
            }
        }
        time++;

    }

}

int main() {
    int r, c, k;

    cin>> r>>c>>k;
    arr.assign(101,vector<int>(101, 0));

    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }
    cout << makeNumber(r, c ,k) << '\n';

    return 0;
}