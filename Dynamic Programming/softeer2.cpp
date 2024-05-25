#include <iostream>
#include <vector>
#include <string>
using namespace std;

string rotateLeft(string str, int index) {
    int size=str.size();
    string result ="";
    int count =0;

    while(count<size) {

        result.push_back(str[(index+count)%size]);
        count++;
    }

    return result;
}
string rotateRight(string str, int index) {
    int size=str.size();
    index = size-index;
    string result ="";
    int count =0;
    while(count<size) {
        result.push_back(str[(index+count)%size]);
        count++;
    }
    return result;
}

string addString(string str1, string str2) {
    string result = "";

    int num=0;
    for(int i=0; i<str1.size(); i++) {
        num = (int)str1[i] -97 + (int)str2[i] -97;
        num = num%26 + 97;

        result.push_back((char)num );
    }

    return result;
}

string subString(string str1, string str2) {
    string result = "";

    int num=0;
    for(int i=0; i<str1.size(); i++) {
        num = (int)str2[i]-97 - (int)str1[i]-97;
        if(num<0)  {
            num = 26 + num;
        }
        num = num%26 + 97;
        result.push_back((char)num);
    }
    return result;
}

int main() {
    string input;
    vector<string> str;
    string ans ="";

    for(int i=0; i<4; i++) {
        cin >>input;
        str.push_back(input);
    }
    if(str[0] =="encrypt") {
        string addStr = addString(str[1], str[3]);
        ans = rotateLeft(addStr, stoi(str[2]));
    }

    if(str[0] =="decrypt") {
        string rotateStr = rotateRight(str[3], stoi(str[2]));
        ans = subString(rotateStr, str[1]);

    }
    cout<<ans<<'\n';
    return 0;
}