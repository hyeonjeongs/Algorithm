#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string makeString(int time) {
    cout<< time<< " :";
    int hour = time/60;
    int minute= time%60;
    string str="";
    if(hour < 10) {
        str+="0";
    }
    str+=to_string(hour);
    str+=":";
    if(minute < 10) {
        str+="0";
    }
    str+=to_string(minute);
    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    // n회, t분 간격, m명 승객
    // 동일 시간일 경우, 제일 뒤에 선다
    string answer = "";

    int time = 540; // 9시
    vector<int> timeMinute;
    vector<bool> visited(timetable.size(), false);

    // string을 다 분으로 바꿔주기
    for(int i=0; i<timetable.size(); i++) {
        int index = timetable[i].find(':');
        int hour = stoi(timetable[i].substr(0,index));
        int minute = stoi(timetable[i].substr(index+1));
        timeMinute.push_back(hour*60+minute);
    }
    sort(timeMinute.begin(), timeMinute.end());

    int cnt =0;
    int current_cnt=0;
    int final =0;
    for(int i=0; i<n; i++) {
        time = 540 + i*t;
        current_cnt =0;
        for(int j=0; j<timeMinute.size(); j++) {

            if(current_cnt>=m) {
                break;
            }
            if(timeMinute[j]<=time && !visited[j]) {
                cnt++;
                current_cnt++;
                visited[j] = true;
                final = timeMinute[j];
            }
        }
    }
    if(cnt< m*n && current_cnt==m) {
        answer = makeString(final -1);
    }else if(cnt <m*n && current_cnt!=m) {
        answer = makeString(time);
    }else {
        answer = makeString(timeMinute[cnt-1]-1);
    }


    return answer;
}