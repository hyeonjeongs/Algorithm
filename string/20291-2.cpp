#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string checkStr(string str) {
    int index = str.find('.');
    return str.substr(index+1);
}

int main() {
    int n;
    cin>>n;
    map<string, int> str;
    vector<string> result;
    string word;

    for(int i=0; i<n; i++) {
        string input;
        cin>> input;
        word = checkStr(input);
        if(str.find(word) == str.end()) {
            str[word] = 1;
            result.push_back(word);
        }else {
            str[word]++;
        }

    }
    sort(result.begin(), result.end());

    for(string s: result) {
        cout<< s <<" " << str[s] <<'\n';
    }
    return 0;

}