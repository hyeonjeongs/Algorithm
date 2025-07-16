#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

string getNumber(int starts, string str) {
    string number= "";
    for(int i=starts; i<str.size(); i++) {
        if(!isdigit(str[i])) {
            break;
        }
        number += str[i];
    }
    return number;
}
bool cmp(string a, string b) {
    int cnt = min(a.size(), b.size());
    for(int i=0; i<cnt; i++) {
        string one="", two="";
        if(isdigit(a[i])) {
            one = getNumber(i, a);
        } else {
            one = a[i];
        }
        if(isdigit(b[i])) {
            two = getNumber(i, b);
        } else {
            two = b[i];
        }
        if(one == two) {
            continue;
        }

        if(isdigit(a[i])) {
            if(isdigit(b[i])) { // a, b 둘다 숫자
                string a_str = "", b_str = "";
                int a_counts = 0, b_counts=0;
                for(int j=0; j<one.size(); j++) {
                    if(one[j] == '0') {
                        a_counts++;
                    } else {
                        break;
                    }
                }
                a_str = one.substr(a_counts);

                for(int j=0; j<two.size(); j++) {
                    if(two[j] == '0') {
                        b_counts++;
                    } else {
                        break;
                    }
                }
                b_str = two.substr(b_counts);
                if(a_str == b_str) {
                    return a_counts < b_counts;
                } else {
                    if(a_str.size() != b_str.size()) {
                        return a_str.size() < b_str.size();
                    } else {
                        return a_str < b_str;
                    }
                }
            } else { // a 숫자, b 문자
                return one < two;
            }
        } else {
            if(isdigit(b[i])) { // a 문자, b 숫자
                return one < two;
            } else {  // a, b 둘다 문자
                char upper_one = toupper(one[0]);
                char upper_two = toupper(two[0]);
                if(upper_one != upper_two) {
                    return upper_one <upper_two;
                } else {
                    return one[0] < two[0];
                }
            }
        }
    }
    return a.size() < b.size();
}

int main() {
    int n;
    vector<string> str;
    cin >> n;
    for(int i=0; i<n; i++) {
        string input;
        cin >> input;
        str.push_back(input);
    }
    sort(str.begin(), str.end(), cmp);

    for(int i=0; i<n; i++) {
        cout << str[i] << "\n";
    }

    return 0;
}
