#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int,int> pi;
vector<bool> visited;
int sum = 0;
void dfs(vector<vector<int>> dungeons, int cnt, int k) {

    if(cnt>sum){
        sum = cnt;
    }

    for(int i=0; i<dungeons.size(); i++) {
        if(!visited[i] && dungeons[i][0]<=k) {
            visited[i] = true;
            dfs(dungeons, cnt+1, k-dungeons[i][1]);
            visited[i] = false;

        }

    }

}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    // 최소 필요 피로도, 소모 피로도
    vector<pi> game;
    visited.assign(dungeons.size(), false);

    dfs(dungeons, 0, k);
    answer = sum;
    return answer;
}