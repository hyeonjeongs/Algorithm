/**
 * 틀린이유 : map에서 값있는지 확인할 때, != 으로 해서 반대로 설정해서 index 오류 발생
 *
 * '!=' -> '==' 으로 변경해서 해당 아이디 없는 경우를 찾기
 */

#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> user;
vector<string> nickname;
int indexs = 0;

void makeData(vector<string> datas) {

    if(datas[0]=="Enter") {

        if(user.find(datas[1]) == user.end()) {
            user[datas[1]] = indexs++;
            nickname.push_back(datas[2]);
            return;
        }
        int index = user[datas[1]];
        nickname[index] = datas[2];

    } else if(datas[0] =="Change") {
        int index = user[datas[1]];
        nickname[index] = datas[2];
    }


}


vector<string> solution(vector<string> record) {
    vector<string> answer;

    for(int i=0; i<record.size(); i++){
        vector<string> datas;
        string buffer;
        istringstream ss(record[i]);
        while(getline(ss, buffer, ' ')) {
            datas.push_back(buffer);
        }
        makeData(datas);

    }

    for(int i=0; i<record.size(); i++) {

        istringstream ss(record[i]);

        string current, id, nick;
        ss >> current >> id >> nick;

        string result = nickname[user[id]];
        if(current == "Enter") {
            result.append("님이 들어왔습니다.");
            answer.push_back(result);
        } else if(current == "Leave") {
            result.append("님이 나갔습니다.");
            answer.push_back(result);
        }

    }

    return answer;
}