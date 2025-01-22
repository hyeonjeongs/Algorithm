#include <iostream>
#include <vector>

using namespace std;
long long mins = 1e10;
long long maxs = 0;

string min_str="";
string max_str = "";
int k;

vector<char> relation;
void calcNum(string str) {

    long long num = stoll(str);

    if(num <mins) {
        mins = num;
        min_str = str;
    }

    if(num > maxs) {
        maxs = num;
        max_str = str;
    }

}

bool calcSize(int a, int b, char ch) {
    if(ch == '<') {
        return a<b;
    }
    if(ch=='>') {
        return a>b;
    }
    return false;
}

void findNum(vector<bool> visited, int index, int num, string str) {
    if(index > k) {
        return;
    }
    if(k==index) {
        calcNum(str);
        return;
    }
    for(int i=0; i<=9; i++) {
        if(visited[i]) {
            continue;
        }
        if(!calcSize(num, i, relation[index])){
            continue;
        }
        string new_str= str + to_string(i);
        visited[i] = true;
        findNum(visited, index+1, i, new_str);
        visited[i] = false;
    }
}


int main() {

    cin >> k;
    relation.assign(k+1, ' ');
    for(int i=0; i<k; i++) {
        cin >> relation[i];
    }



    for(int i=0; i<=9; i++) {
        vector<bool> visited(10, false);
        visited[i] = true;
        findNum(visited, 0, i, to_string(i));

    }

    cout << max_str << '\n' << min_str <<'\n';

    return 0;
}