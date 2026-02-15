#include<iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> maps;
string s;
vector<int> visited;
int dfs (int index) {
    if (index>=s.length()) {
        return 1;
    }

    if (visited[index] != -1) {
        return visited[index];
    }
    for (int i=1; i + index <= s.length(); i++) {
        string sub = s.substr(index, i);
        if (maps.find(sub) != maps.end()) {
            if (dfs(index+i)) {
                return visited[index] = 1;
            }
        }
    }
   return visited[index] = 0;
}

int main() {

    int n;
    cin >> s;
    cin >> n;
    visited.assign(s.length(), -1);

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        maps[str] = 1;
    }

    bool is_possible= dfs(0);
    if (is_possible) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}