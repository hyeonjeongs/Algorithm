#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str, out;
    cin >> str;
    cin >> out;
    string result = "";


    for(char ch: str) {
        result+= ch;

        if(result.size()>=out.size()  && result.substr(result.size()-out.size(), out.size()) == out) {
            result.erase(result.end() - out.size(), result.end());
        }
    }

    if(result==""){
        result = "FRULA";
    }
    cout << result << '\n';

    return 0;
}