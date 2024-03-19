#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<int> sort_num = priorities;
    queue<int> que;
    sort(sort_num.begin(), sort_num.end(), greater<>());

    for(int i=0; i<priorities.size(); i++) {
        que.push(i);
    }
    int out = -1, index=0;
    int max_num = sort_num[index];
    while(1) {
        if(out == location) {
            answer = index;
            break;
        }
        if(priorities[que.front()]>=max_num) {
            out = que.front();
            que.pop();
            max_num = sort_num[++index];
        } else {
            int num = que.front();
            que.pop();
            que.push(num);
        }
    }


    return answer;
}