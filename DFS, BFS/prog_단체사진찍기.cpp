#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool checkDiff(int firsts, int seconds, int diff, char comp) {

    int current_diff = abs(firsts-seconds) -1;


    if(comp == '>') {
        if(current_diff > diff) {
            return true;
        }
    } else if(comp == '<') {
        if(current_diff < diff) {
            return true;
        }
    } else {
        if(current_diff == diff) {
            return true;
        }
    }
    return false;
}
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool status = true;
        for(int i=0; i<data.size(); i++) {
            int firsts = friends.find(data[i][0]);
            int seconds = friends.find(data[i][2]);
            char diff = data[i][4];

            if(!checkDiff(firsts, seconds, diff-'0', data[i][3])) {
                status = false;
                break;
            }
        }
        if(status) {
            answer++;
        }
    } while(next_permutation(friends.begin(), friends.end()));

    return answer;
}