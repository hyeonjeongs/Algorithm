#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = -1;
    sort(citations.begin(), citations.end());

    int front = citations[0];
    int end = citations[citations.size()-1];


    for(int i=front; i<=end; i++){

        int small = lower_bound(citations.begin(), citations.end(), i) - citations.begin();
        small = citations.size() - small;
        if(small >= i) {
            answer = max(answer, i);
        }
    }
    if (answer == -1) {
        answer = citations.size();
    }


    return answer;
}