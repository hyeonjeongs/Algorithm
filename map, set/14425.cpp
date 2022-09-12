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