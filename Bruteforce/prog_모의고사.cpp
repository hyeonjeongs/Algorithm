#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> people(3,0);

    vector<vector<int>> number = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};

    for(int i=0; i<answers.size(); i++) {
        int result = answers[i];
        if(number[0][i%5] == result) {
            people[0]++;
        }
        if(number[1][i%8] == result) {
            people[1]++;
        }
        if(number[2][i%10] == result) {
            people[2]++;
        }
    }

    int maxs = 0;
    for(int i=0; i<3; i++) {
        maxs = max(maxs, people[i]);
    }
    for(int i=0; i<3; i++) {
        if(people[i] == maxs) {
            answer.push_back(i+1);
        }
    }
    return answer;
}