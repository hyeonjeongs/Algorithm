#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >>n;
    map<string, int> maps;
    vector<string> strs;
    string buffer;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        istringstream ss(str);
        string a;
        while(getline(ss, buffer, '.')) {
            a = buffer;
        }
        istringstream sss(str);

        if(maps.find(a) != maps.end() ) {
            maps[a]++;
        }else {
            maps[a] =1;
            strs.push_back(a);
        }
    }
    sort(strs.begin(), strs.end());
    for(int i=0; i<strs.size(); i++) {
        cout << strs[i] <<" " << maps[strs[i]] << '\n';
    }

    return 0;
}