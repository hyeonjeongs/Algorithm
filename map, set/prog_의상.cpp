#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<int> result;
    map<string, int> cloth;


    for(int i=0; i<clothes.size(); i++) {
        if(cloth.find(clothes[i][1]) != cloth.end()) {
            result[cloth[clothes[i][1]]]++;
        } else {
            cloth.insert({clothes[i][1],result.size()});
            result.push_back(1);
        }
    }
    for(int i=0;i<result.size(); i++) {
        answer *= result[i]+1;
    }

    return answer-1;
}