#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
#define MAX 1001

vector<bool> visit(MAX, false);

vector<vector<bool>> aMatrix; //인접행렬
vector<vector<int>> aList; //인접 리스트

/*
dfs - 인접행렬, 인접리스트, 재귀
bfs - 인접행렬, 인접리스트
*/


// DFS - 인접행렬, 인접리스트
void dfs(int n, int v) {
    stack<int> st; //스택 활용
    vector<bool> visited(n + 1, false);// 방문 체크

    st.push(v);
    visited[v] = true;

    while (!st.empty()) {
        int node = st.top();
        cout << node << ' ';
        st.pop();
        //인접행렬
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && aMatrix[node][i]) {
                st.push(i);
                visited[i] = true;
                break;
            }
        }

        //인접 리스트
        for (int i = 0; i < aList[node].size(); i++) {
            if (!visited[aList[node][i]]) {
                st.push(aList[node][i]);
                visited[aList[node][i]] = true;
                break;
            }
        }
    }

}

//DFS - 재귀
void Dfs(int v) {
    if (visit[v])
        return;
    visit[v] = true;
    cout << v << ' ';
    for (int i = 0; i < aList[v].size(); i++) {
        Dfs(aList[v][i]);
    }
}

//BFS - 인접행렬, 인접리스트
void bfs(int n, int v) {
    vector<int> result;
    queue<int> que;
    vector<bool> visited(n + 1, false);

    que.push(v);
    visited[v] = true;


    while (!que.empty()) {
        int node = que.front();
        cout << node << ' ';
        que.pop();

        // 인접 행렬
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && aMatrix[node][i]) {
                que.push(i);
                visited[i] = true;
            }
        }

        //인접리스트
        for (int i = 0; i < aList[node].size(); i++) {
            if (!visited[aList[node][i]]) {
                que.push(aList[node][i]);
                visited[aList[node][i]] = true;
            }
        }
    }

}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    aMatrix.assign(n + 1, vector<bool>(n + 1, false));
    aList.assign(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        //인접행렬
        aMatrix[a][b] = true;
        aMatrix[b][a] = true;

        //인접리스트
        aList[a].push_back(b);
        aList[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(aList[i].begin(), aList[i].end());
    }

    //DFS - 재귀
    Dfs(v);
    //dfs(n, v);
    cout << '\n';

    bfs(n, v);

    return 0;
}