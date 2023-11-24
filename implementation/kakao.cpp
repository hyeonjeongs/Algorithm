#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
using namespace std;
map<char,int> term;

int split(string today) {
    istringstream ss(today);
    string buffer;

    string str="";
    int str_num=0;


    // today 배열에 할당하기 (2022 05 19)
    while(getline(ss, buffer, '.')){
        str.append(buffer);
    }

    for(int i=0; i<str.size(); i++) {
        int multiple = 1e7;
        multiple /= pow(10,i);
        str_num += (str[i]-'0')*multiple;
    }
    return str_num;
}

int makeResult(string pri) {
    string privacyDate, termData, month;
    int date, month_num;
    istringstream ss(pri);
    ss.str();

    ss>>privacyDate>>termData;

    date = split(privacyDate);
    privacyDate = to_string(date);
    month.append(to_string(privacyDate[4]-'0'));
    month.append(to_string(privacyDate[5]-'0'));
    month_num = stoi(month);

    int add_year, add_month;
    if(month_num + term[termData[0]]>12) {
        add_year = (month_num + term[termData[0]])/12;
        add_month = (month_num + term[termData[0]])%12;
        date += add_year*1000 + add_month*100-1;
    } else {
        date += term[termData[0]] *100 -1;
    }
    return date;
}

int main() {
    string today;
    vector<string> terms;
    int date = split(today);
    vector<int> answer;
    vector<string> privacies;

    // terms map으로 할당하기
    for(int i=0; i<terms.size(); i++){
        string terms_string = terms[i];
        term[terms_string[0]] = terms_string[2]-'0';
    }
    for(int i=0; i<privacies.size(); i++) {
        string pri = privacies[i];
        int current_date = makeResult(pri);
        if(current_date > date) {
            answer.push_back(i+1);
        }
    }

    for(int i=0; i<answer.size(); i++) {
        cout<< answer[i] <<endl;
    }

    return 0;
}