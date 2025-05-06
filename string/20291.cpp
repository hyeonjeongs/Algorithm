#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void formatSave(map<string, int> &file, string input, vector<string> &str) {

    int index = input.find('.');
    string name = input.substr(index+1);

    if(file.find(name) == file.end()) {
        file[name] =1;
        str.push_back(name);
        return;
    }

    file[name]++;
}

int main() {

    int n;
    map<string, int> file;
    vector<string> str;

    cin>>n;
    for(int i=0; i<n; i++) {
        string input;
        cin>>input;
        formatSave(file, input, str);
    }
    sort(str.begin(), str.end());

    for(int i=0; i<str.size(); i++) {
        cout<< str[i] << " " << file[str[i]] <<'\n';
    }

    return 0;
}

/*

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
 */