#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> country;
vector<vector<bool>> visited;
int dx[] ={-1,1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int y, int x, int index) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>country[i][j];
        }
    }
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++) {
            dfs(i, j,0);
        }
    }
}

int main() {

    int n;
    country.assign(n, vector<int>(n,0));
    visited.assign(n, vector<bool>(n,false));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>country[i][j];
        }
    }
    for(int i=1; i<n-1; i++){
        for(int j=1; j<n-1; j++) {
            dfs(i, j,0);
        }
    }
}