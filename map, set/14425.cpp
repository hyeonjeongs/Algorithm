#include <iostream>
#include <vector>
#include <set>
using namespace std;

int strFind(int m, set<string> &s){
    string str;
    int result =0;
    while(m--){
        cin>>str;
        if(s.find(str) != s.end()) // 배열에서 찾지 못한경우 s.end() 출력
            result++; //s안에 있으면 값 증가
    }

    return result;
}

int main(){
    int n,m, result=0;
    cin>>n>>m;
    set<string> s;
    string str;

    while(n--){
        cin>>str;
        s.insert(str);
    }

    cout<<strFind(m,s)<<'\n';

    return 0;
}

/*
 *
#include <iostream>
#include <map>

using namespace std;

int num=0;

void strCheck(string input, map<string,bool>& str) {
    if(str.find(input) != str.end()){
        num++;
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    map<string, bool> str;
    string input;

    for(int i=0; i<n; i++) {

        cin>>input;
        str.insert({input, true});

    }
    for(int i=0; i<m; i++) {
        cin>>input;
        strCheck(input, str);
    }
    cout<<num<<'\n';
    return 0;
}
 */