#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <string>

using namespace std;
map<char,int> term;

int split(string today) {
    istringstream ss(today);
    string buffer;

    vector<string> str;

    while(getline(ss, buffer, '.')){
        str.push_back(buffer);
    }

    int year, month, day, total;
    year = stoi(str[0]); month = stoi(str[1]); day = stoi(str[2]);
    total = year * 12 * 28 + (month-1) * 28 + day;

    return total;
}

int makeResult(string pri) {
    string privacyDate, termData, month="";
    int date, month_num;
    istringstream ss(pri);
    ss.str();

    ss>>privacyDate>>termData;

    date = split(privacyDate) + (term[termData[0]]*28-1);

    return date;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int date = split(today);

    for(int i=0; i<terms.size(); i++){
        string terms_string, terms_int;
        istringstream ss(terms[i]);
        ss.str();
        ss>>terms_string>>terms_int;

        term[terms_string[0]] = stoi(terms_int);
    }

    for(int i=0; i<privacies.size(); i++) {
        string pri = privacies[i];
        int current_date = makeResult(pri);

        if(current_date < date) {
            answer.push_back(i+1);
        }
    }


    return answer;
}