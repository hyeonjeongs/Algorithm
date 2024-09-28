#include <iostream>
#include <vector>

using namespace std;

int moveTruck(vector<int> weight, int w, int l, int n) {
    vector<int> bridge(w+1, 0);
    int time=0;
    int index=0;
    int current_weight=0;
    while(index<=n) {
        if(index>=n && current_weight==0 && time>0){
            break;
        }

        time++;

        // 한 칸 옮기기
        for(int i=w-1; i>=0; i--) {
            if(bridge[i]==0){
                continue;
            }
            if(i==w-1) {
                current_weight-=bridge[i];
            }
            bridge[i+1] = bridge[i];
            bridge[i] = 0;
        }

        // 입장 여부 확인
        if(current_weight + weight[index] > l || bridge[0]>0 || index==n) {
            continue;
        }

        // 새로운 것 입장
        current_weight += weight[index];
        bridge[0] = weight[index++];


    }
    return time;
}

int main() {
    int n, w, l;
    cin>> n>> w>> l;
    vector<int> weight(n,0);

    for(int i=0; i<n; i++) {
        cin>>weight[i];
    }

    cout << moveTruck(weight, w, l, n);


    return 0;
}