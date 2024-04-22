#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

bool subNum(int num, vector<int> stones, int k) {
    int cnt = 0;
    int index = -5;

    for(int i=0; i<stones.size(); i++) {
        stones[i] -= num;
        if(stones[i] <=0) {
            if(cnt>0 && index+1==i) {
                cnt++; index = i;
            } else {
                cnt = 1; index = i;
            }

            if(k<=cnt) {
                return false;
            }
        }
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    ll sum=0;



    for(int i=0; i<stones.size(); i++){
        sum+= stones[i];
    }
    ll left = 0, right = sum;
    ll mid =0;
    vector<int> copy = stones;
    while(1) {
        cout<< mid << endl;
        if(left>right){
            break;
        }
        mid = (left+right)/2;
        if(subNum(mid, copy, k)) {
            left = mid+1;
        } else {
            right = mid-1;
        }

    }
    answer = left;
    return answer;
}