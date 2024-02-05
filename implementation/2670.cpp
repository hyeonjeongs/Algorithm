#include <iostream>
#include <vector>
#include<math.h>

using namespace std;


bool similarWord(string origin, string str, vector<int> alpha) {
    int cnt=0;
    int origin_size = origin.size();
    int str_size = str.size();

    int diff = abs(origin_size - str_size);

    if(diff>1) {
        return false;
    }

    for(int i=0; i<str.size(); i++) {
        int ch = str[i]-'A';
        if(alpha[ch]>0) {
            alpha[ch]--;
        }else{
            cnt++;
        }
    }

    if(cnt<=1){
        return true;
    }

    return false;
}

int main() {
    int n, result=0;
    vector<int> alpha(26,0);
    string str;
    cin>>n;
    cin>>str;

    for(int i=0; i<str.size(); i++) {
        alpha[str[i]-'A']++;
    }

    for(int i=0; i<n-1; i++) {
        string input;
        cin>> input;
        if(similarWord(str,input, alpha)) {
            result++;
        }
    }
    cout<<result;

    return 0;
}