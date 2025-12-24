#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for(int i=1; i<=s.length()/2; i++) {
        int cnt =1;
        string str = "";

        string current = s.substr(0, i);
        for(int j=i; j<s.length(); j+=i) {
            if(current == s.substr(j, i)) {
                cnt++;
            } else {
                if(cnt>1) {
                    str+=to_string(cnt);
                }
                str+=current;
                current = s.substr(j, i);
                cnt = 1;
            }
        }
        if(cnt>1) {
            str+=to_string(cnt);
        }
        str+=current;
        int sizes = str.length();
        answer = min(answer, sizes);
    }


    return answer;
}