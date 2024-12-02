#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int appech_score=0;
int max_score = -1;
vector<int> result;
vector<int> copy_info;
int total = 0;
int max_dist = -1;
vector<bool> visited;
void dfs(int cnt, int index, vector<int> score) {

    if(cnt == total) {

        int lion = 0;
        int appeach = 0;
        for(int i=0; i<11; i++) {
            if(copy_info[i]==0 && score[i] == 0) {
                continue;
            }
            if(copy_info[i] < score[i]) {
                lion += 10-i;
            } else {
                appeach += 10-i;
            }
        }
        if(appeach < lion) {
            int dist = lion - appeach;
            if(max_dist < dist) {
                result = score;
                max_dist = dist;
            } else if(max_dist==dist) {
                for(int i=10; i>=0; i--) {
                    if(result[i] < score[i]) {
                        result = score;
                        break;
                    } else if(result[i] > score[i]){
                        return;

                    }
                }
            }
        }
        return;
    }

    for(int i=index; i<11; i++) {

        int current_cnt = copy_info[i]+1;

        if(current_cnt + cnt > total) {
            current_cnt = total - cnt;
        }
        score[i] = current_cnt;
        dfs(current_cnt+cnt, index+1, score);
        score[i] = 0;

    }

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    vector<int> score;
    score.assign(11, 0);

    copy_info = info;
    total = n;
    dfs(0, 0, score);

    if(result.size() == 0) {
        answer.push_back(-1);
    }else {
        answer = result;
    }

    return answer;
}