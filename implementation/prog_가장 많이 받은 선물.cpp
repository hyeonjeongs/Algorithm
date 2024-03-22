#include <string>
#include <vector>
#include <map>
#include <algorithm>
// 9:5

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int cnt = friends.size();
    vector<vector<int>> result(cnt, vector<int>(cnt,0));
    vector<vector<int>> gift_number(cnt, vector<int>(3,0)); // 선물지수
    map<string, int> maps;
    for(int i=0; i<cnt; i++){
        maps[friends[i]] = i;
    }
    
    for(int i=0; i<gifts.size();i++){
        int index= gifts[i].find(' ');
        string give = gifts[i].substr(0,index);
        string send = gifts[i].substr(index+1);
        
        result[maps[give]][maps[send]]++;
        gift_number[maps[give]][0]++;
        gift_number[maps[send]][1]++;
    }
    
    for(int i=0; i<cnt; i++) {
        gift_number[i][2] = gift_number[i][0] - gift_number[i][1];
    }
    
    // 답 구하기
    vector<int> answers(cnt, 0);
    for(int i=0; i<cnt-1; i++) {
        for(int j=i+1; j<cnt; j++) {
            if(i==j){
                continue;
            }
            // 서로 준 기록 있으면
            int a = result[i][j]; // i가
            int b = result[j][i]; // j가
            
            if(a > b) {
                answers[i]++;
              
            } 
            else if(a < b) {
                answers[j]++;
        
            } 
            else{
                
                if(gift_number[i][2] == gift_number[j][2]){
                    continue;
                }
                if(gift_number[i][2] < gift_number[j][2]){
                    answers[j]++;
                } else {
                    answers[i]++;
                }
            }
        }
    }
    
    sort(answers.begin(), answers.end(), greater<>());
    answer = answers[0];
    
    return answer;
}