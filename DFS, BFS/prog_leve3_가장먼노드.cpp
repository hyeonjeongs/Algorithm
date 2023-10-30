#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> aList;

int bfs(int n, int v) {
    queue<int> que;
    vector<bool> visit(n+1, false);
    vector<int> distance(n+1,0);
    int num =1;

    que.push(v);
    visit[v]=true;

    while(!que.empty()) {

        int node = que.front();
        que.pop();
        for(int i=0; i<aList[node].size(); i++){
            if(!visit[aList[node][i]]){
                que.push(aList[node][i]);
                visit[aList[node][i]] = true;
                distance[aList[node][i]] = distance[node]+1;
            }
        }
    }
    sort(distance.begin(), distance.end(), greater<>());
    for(int i=1; i<=n; i++){
        if(distance[i] != distance[i-1])
            return num;
        num++;
    }

    return num;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    aList.assign(n+1, vector<int>());

    for(int i=0; i<edge.size(); i++) {
        aList[edge[i][0]].push_back(edge[i][1]);
        aList[edge[i][1]].push_back(edge[i][0]);
    }

    answer = bfs(n, 1);

    return answer;
}