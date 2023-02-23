#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
vector<vector<int>> aList;
vector<vector<bool>> aMatrix;
vector<bool> visit(1001, false);

// dfs 재귀
void dfsList(int v){
    if(visit[v]){
        return;
    }

    visit[v] = true;
    cout<< v << ' ';
    for(int i=0; i<aList[v].size(); i++){
        dfsList(aList[v][i]);
    }
}

void bfs(int v, int n){
    vector<bool> visited(n+1,false);
    queue<int> check;

    check.push(v);
    visited[v] = true;

    while(!check.empty()){
        int node = check.front();
        cout<< node<< ' ';
        check.pop();

        for(int i=1; i<=n; i++){
            if(!visited[i] && aMatrix[node][i]){
                check.push(i);
                visited[i]= true;
            }
        }

        //인접 리스트로 bfs
        /*for(int i=0; i<aList[node].size(); i++){
            if(!visited[aList[node][i]]){
                check.push(aList[node][i]);
                visited[aList[node][i]] = true;
            }
        }*/
    }

}

int main(){
    int n,m,v;
    cin>>n>>m>>v;

    aList.assign(n+1, vector<int>());
    aMatrix.assign(n+1, vector<bool>(n+1, false));

    for(int i=0; i<m; i++){
        int a, b;
        cin>> a>>b;

        aList[a].push_back(b);
        aList[b].push_back(a);

        aMatrix[a][b] = true;
        aMatrix[b][a] = true;
    }

    /*
     * 주의 ! 정점 번호 작은 것부터 방문 해야 하므로 여기서 정렬 해줘야함
     */
    for(int i=1; i<=n; i++){
        sort(aList[i].begin(), aList[i].end());
    }

    dfsList(v);
    cout<<'\n';
    bfs(v, n);
    return 0;
}