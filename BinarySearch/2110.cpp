#include<iostream>
#include<vector>
#include <algorithm>

/**
 * 다시 풀어보기
 */

using namespace std;
vector<int> house;
int router(int dist){
    int cnt =1;
    int pos = house[0];

    for(int i=1; i<house.size(); i++){
        if(house[i]-pos < dist)
            continue;
        cnt++;
        pos = house[i];
    }

    return cnt;
}

int binarySearch(int c,int left, int right){
    int maxNum = 0;

    while(left<=right){
        // 가장 인접한 공유기 사이의 거리가 mid일때 공유기 c개 설치 가능한가
        int mid = (left+right)/2; // 사이 거리

        int installed = router(mid);
        if(installed < c){ // 더 설치되어야 하는 경우 -> 거리를 줄인다
            right = mid-1;
        } else {
            maxNum = mid;
            left = mid + 1;
        }
    }

    return maxNum;
}

int main() {
    int n, c;

    cin>> n>> c;
    house.assign(n,0);

    for(int i=0; i<n; i++){
        cin>> house[i];
    }
    sort(house.begin(), house.end());

    // left : 공유기 사이 최단 거리
    // right : 공유기 사이 최장 거리
    cout << binarySearch(c, 1, house[n-1]-house[0]) << '\n';

    return 0;
}