/**
 * 이렇게 풀면 "BBABAAAAAAB" 이런거 안됨 (왼쪽 갔다가 오른쪽으로 다시 가는거)
 * 다시 풀어봐야하듯
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(string name) {
    int answer = 0;
    int size = name.length();
    vector<bool> visited;
    vector<int> num;
    visited.assign(size, false);

    int cnt =0;

    // 알파벳 변경
    for(int i=0; i<size; i++) {
        int next = name[i] -'A';
        int before = 'Z' - name[i] + 1;

        int result = min(next, before);
        num.push_back(result);
        answer += result;
    }


    // 알파벳 이동
    int index = 0;
    int result=0;

    for(int i=0; i<size; i++) {
        if(num[i] == 0) {
            continue;
        }
        int r_index = i - index;
        int l_index = index + (size-i);

        if(r_index<=l_index) {
            result+=r_index;

        } else {
            result+=l_index;

        }
        index = i;

    }
    // 왼쪽으로 이동
    int result_left=0;
    index =0;
    for(int i=size-1; i>=0; i--) {
        if(num[i] == 0) {
            continue;
        }
        int r_index = (i-index+size)%size;
        int l_index = (index + (size-i))%size;

        if(r_index<l_index) {
            result_left+=r_index;

        } else {
            result_left+=l_index;
        }
        index = i;

    }
    cout << result <<"," << result_left <<endl;
    answer += min(result, result_left);

    return answer;
}