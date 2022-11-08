#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<bool> solution(vector<string> members, vector<vector<string>> commands, vector<string> messageIDs) {
    vector<bool> answer;
    int i;
    for(int j=0; j<messageIDs.size(); j++){
        bool w_state = false, t_state= false;


        for(int i=commands.size()-1; i>0; i--){
            if(commands[i][1] == "MY"){
                w_state = true;
            }
            if(w_state == true && commands[i][2] == messageIDs[j]){
                answer.push_back(true);
                t_state = true;
            }

        }
        if(t_state == false){
            answer.push_back(false);
        }

    }

    return answer;
}

int main(){


}

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> members, vector<vector<string>> commands, string messageID) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int answer=0;

    // members index로 구분해주기
    map<string, bool> member;
    member["MY"] = false;
    for(int j=0; j<members.size(); j++){
        member[members[j]] = false;
    }

    int i= commands.size() -1;

    while(commands[i][2] != messageID){
        member[commands[i][1]] = true;
        i--;
    }
    member[commands[i][1]] = true;

    for(int j=0; j<members.size(); j++){
        if(member[members[j]]){
            answer++;
        }
    }
    if(member["MY"]){
        answer++;
    }
    answer = members.size() + 1 - answer;

    return answer;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 입장 전인지 확인
int solution(vector<vector<string>> commands, string messageID) {
    int answer = 0;
    int total_member = 1;

    // members index로 구분해주기
    map<string, bool> member;
    member["MY"] = false;
    for(int j=0; j<commands.size(); j++){
        if(commands[j][0] =="I"){
            member[commands[j][1]] = false;
            total_member++;
        }
    }

    int i= commands.size() -1;

    while(commands[i][2] != messageID){
        if(!member[commands[i][1]]){
            member[commands[i][1]] = true;
            answer++;
        }
        i--;
    }
    if(!member[commands[i][1]]){
        member[commands[i][1]] = true;
        answer++;
    }

    answer = total_member - answer;

    return answer;
}

vector<string> solution(vector<string> dictionary, vector<vector<string>> command) {
    vector<string> answer;
    char str[100];
    int j=0;
    dictionary[0].copy(str,dictionary[0].length());
    std::copy(dictionary.begin(), dictionary.end(),)
    strcpy(str, dictionary[j].c_str);
    sort(dictionary.begin(), dictionary,end());
    return answer;
}