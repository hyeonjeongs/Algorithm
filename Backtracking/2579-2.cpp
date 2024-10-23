#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<bool> visited;
vector<char> arrow;
vector<string> num_str;

bool isPossible(char a, char b, char oper) {
    if(oper == '>') {
        if(a<b) {
            return false;
        }
    }
    else if(oper == '<') {
        if(a>b) {
            return false;
        }
    }
    return true;
}

void dfs(int index, string str) {
    if(index == k+1){
        num_str.push_back(str);
        return;
    }

    for(int i=0; i<=9; i++) {
        if(visited[i]) {
            continue;
        }
        if(index == 0 || isPossible(arrow[index-1],i+'0', arrow[index-1])) {
            visited[i] = true;
            dfs(index+1, str+to_string(i));
            visited[i] = false;
        }

    }



}

int main() {

    cin >>k;

    arrow.assign(k, ' ');
    visited.assign(10, false);

    for(int i=0; i<k; i++) {
        cin >> arrow[i];
    }

    dfs(0, "");

    sort(num_str.begin(), num_str.end());
    cout << num_str[num_str.size()-1] <<'\n'<< num_str[0];


    return 0;
}