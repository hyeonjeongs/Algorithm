//#include <iostream>
//#include <sstream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >>n;
//    map<string, int> maps;
//    vector<string> strs;
//    string buffer;
//
//    for(int i=0; i<n; i++) {
//        string str;
//        cin >> str;
//        istringstream ss(str);
//        string a;
//        while(getline(ss, buffer, '.')) {
//            a = buffer;
//        }
//        istringstream sss(str);
//
//        if(maps.find(a) != maps.end() ) {
//            maps[a]++;
//        }else {
//            maps[a] =1;
//            strs.push_back(a);
//        }
//    }
//    sort(strs.begin(), strs.end());
//    for(int i=0; i<strs.size(); i++) {
//        cout << strs[i] <<" " << maps[strs[i]] << '\n';
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    map<string, int> maps;
    vector<string> results;
    cin >> n;
    for(int i=0;i <n; i++){
        string str;
        cin >> str;
        istringstream ss(str);
        string buffer;
        vector<string> current;
        while(getline(ss, buffer, '.')) {
            current.push_back(buffer);
        }
        if(maps.find(current[1]) != maps.end()) {
            maps[current[1]]++;
        }else {
            maps[current[1]] = 1;
            results.push_back(current[1]);
        }

    }
    sort(results.begin(), results.end());

    for(int i=0; i< results.size(); i++) {
        cout << results[i]<<" " << maps[results[i]] <<'\n';
    }

    return 0;
}