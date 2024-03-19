#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;
    int out_index =0, in_index=0;
    int time=1;
    int truck_weight = truck_weights[in_index];

    //대기트럭 비우기
    bridge.push(time);
    while(out_index<truck_weights.size()) {
        time++;
        // 현재시간 - 들어간 시간 = weight 이면 나오기
        if(!bridge.empty()&& time-bridge.front()==bridge_length) {
            truck_weight -=truck_weights[out_index++];
            bridge.pop();
        }

        if(truck_weight+truck_weights[in_index+1]<=weight && bridge.size()<bridge_length) {
            bridge.push(time);
            truck_weight+= truck_weights[++in_index];

        }
    }

    answer = time;

    return answer;
}