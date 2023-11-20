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