#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> phone_map;

    for(string phone_number : phone_book) {
        phone_map[phone_number] = 1;
    }

    for(string phone_number : phone_book) {
        for(int i=1; i<phone_number.size(); i++) {
            string phone_str = phone_number.substr(0,i);
            if(phone_map[phone_str] == 1) {
                answer = false;
                break;
            }
        }
    }

    return answer;
}