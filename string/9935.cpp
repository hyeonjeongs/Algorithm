#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str, pops, new_str="";
    cin >> str;
    cin >> pops;
    int length= pops.size();
    string res = "";

    for(auto &ch: str) {
        res+=ch;
        if(res.size()>=length && res.substr(res.size()-length, length) == pops) {
            res.erase(res.end()-length, res.end());
        }
    }

    if(res==""){
        res = "FRULA";
    }
    cout << res;
    return 0;

}