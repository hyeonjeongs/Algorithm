#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;

bool calcNumber(int current) {

    int number_count = 0; // 6자리 안되면 0 쓴 것
    vector<string> time_string;

    time_string.push_back(to_string(current/60/60));
    time_string.push_back(to_string(current%(60*60)/60));
    time_string.push_back(to_string(current%(60*60)%60));

    map<char, int> time_map;
    int result_count = 0;

    for(int i=0; i<time_string.size(); i++) {
        string i_string = time_string[i];

        for(int j=0; j<i_string.length(); j++) {
            number_count++;

            if(time_map.find(i_string[j])==time_map.end()) {
                time_map[i_string[j]] = 1;
                result_count++;
            }

        }

    }
    if(number_count<6 && time_map['0']!=1) {
        result_count++;
    }

    if(result_count<=2){
        return true;
    }
    return false;

}

int solution(string &S, string &T) {
    int answer = 0;
    vector<int> start_time;
    vector<int> end_time;
    int starts, ends;

    istringstream ss(S);
    string buffer;
    while(getline(ss, buffer, ':')) {
        start_time.push_back(stoi(buffer));
    }

    istringstream st(T);
    while(getline(st, buffer, ':')) {
        end_time.push_back(stoi(buffer));
    }

    starts = start_time[0]*60*60 + start_time[1]*60 + start_time[2];
    ends = end_time[0]*60*60 + end_time[1]*60 + end_time[2];

    for(int i=starts; i<=ends; i++) {
        if(calcNumber(i)) {
            answer++;
        }
    }

    return answer;
}
