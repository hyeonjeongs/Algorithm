#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<bool> visited;
int rol, col;
int result = 0;
void bfs(int index, int num, vector<vector<int>> ability) {
    if(index == col) {
        result= max(result, num);
        return;
    }
    for(int i=0; i<rol; i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        bfs(index+1,num+ability[i][index], ability);
        visited[i] = false;
    }
}
int solution(vector<vector<int>> ability) {
    int answer = 0;
    rol= ability.size();
    col= ability[0].size();
    visited.assign(rol, false);
    bfs(0,0, ability);
    answer = result;
    
    return answer;
}