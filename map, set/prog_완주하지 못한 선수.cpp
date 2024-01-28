#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> completionMap;

    for(int i=0; i<completion.size(); i++) {
        if(completionMap.find(completion[i]) != completionMap.end()) {
            completionMap[completion[i]]++;
        }
        completionMap.insert({completion[i], 1});
    }

    for(int i=0; i<participant.size(); i++) {
        if(completionMap[participant[i]]<=0) {
            answer = participant[i];
            break;
        }
        completionMap[participant[i]]--;
    }


    return answer;
}