#include <string>
#include <vector>
#include <iostream>
// 8:30
using namespace std;

vector<bool> visited;
int mins = 100;

void changeWords(string begin, vector<string> words, string target, int result) {

    if(begin == target) {
        mins = min(mins, result);
        return;
    }

    for(int i=0; i<words.size(); i++) {
        int cnt=0;
        if(visited[i]) {
            continue;
        }
        for(int j=0; j<begin.length(); j++) {
            if(words[i][j] != begin[j]) {
                cnt++;
            }
            
        }

        if(cnt==1) {
            visited[i] = true;
            changeWords(words[i], words, target, result+1);
            visited[i] = false;
        }

    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    cout<< begin.length()<<"sdfsdfsd"<<endl;
    visited.assign(begin.length(), false);

    changeWords(begin, words, target, 0);

    if(mins == 100) {
        answer = 0;
    }
    else {
        answer = mins;
    }

    return answer;
}