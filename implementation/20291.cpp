#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<string ,int> ci;

void formatSave(string str, map<string, int> &file_num, vector<string> &files){

    int index = str.find('.');
    string name = str.substr(index+1);


    if(file_num.find(name) == file_num.end()){
        file_num[name] = 1;
        files.push_back(name);
        return;
    }

    file_num[name]++;

}

int main(){
    int n;

    cin>> n;
    vector<string> files;
    map<string, int> file_num;

    for(int i=0; i<n; i++){
        string input;
        cin>> input;
        formatSave(input, file_num, files);
    }

    sort(files.begin(), files.end());

    for(int i=0; i<files.size(); i++){
        cout << files[i] << " " << file_num[files[i]] << '\n';
    }

    return 0;
}