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
    cout << answer << endl;
    int move = size-1;
    for(int i=0; i<size; i++) {
        int cursor=i+1;
        while(name[cursor]=='A' && cursor<size) {
            cursor++;
        }
        move = min(move, i+ size-cursor + min(i, size-cursor));
    }


    answer += move;

    return answer;
}