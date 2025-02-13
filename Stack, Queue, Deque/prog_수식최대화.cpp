#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;
long long maxs=0;
vector<string> exp_str;
bool isString(string str) {
    return atoi(str.c_str()) ==0 && str.compare("0")!=0;
}
long long calc(long long a, long long b, string opt) {
    if(opt == "+"){
        return a+b;
    }else if(opt == "-") {
        return a-b;
    }
    return a*b;
}
long long calcExp(vector<int> opt, deque<string> number) {

    deque<string> copys;
    deque<string> deletes;

    for(int i=0; i<3; i++) {
        int cur_opt = opt[i];
        while(!number.empty()) {
            string str = number.front();
            number.pop_front();

            if(isString(str) && str == exp_str[cur_opt]) {
                long long first = stoll(copys.back());
                long long second = stoll(number.front());
                copys.pop_back();
                number.pop_front();
                copys.push_back(to_string(calc(first, second, str)));
            } else {
                copys.push_back(str);
            }
        }
        number = copys;
        copys= deletes;
    }

    return abs(stoll(number.back()));
}

long long solution(string expression) {

    long long answer = 0;
    vector<int> exp = {0,1,2};
    exp_str = {"+", "-", "*"};
    deque<string> number;

    int index = 0;

    for(int i=0; i<expression.length(); i++) {
        if(!isdigit(expression[i])) {
            number.push_back(expression.substr(index, i-index));
            string str(1, expression[i]);
            number.push_back(str);
            index= i+1;
        }
    }

    number.push_back(expression.substr(index, expression.size()-index));

    do{
        vector<int> arr(3, 0);
        for(int i=0; i<3; i++) {
            arr[i] = exp[i];
        }

        maxs = max(maxs, calcExp(arr, number));
    } while(next_permutation(exp.begin(), exp.end()));
    answer= maxs;
    return answer;
}