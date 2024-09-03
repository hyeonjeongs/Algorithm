#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> virus;
vector<bool> visited;
int result=0;
void dfs(int node) {

    visited[node]= true;
    result++;

    for(int i=0; i<virus[node].size(); i++) {
        int num = virus[node][i];
        if(visited[num]) {
            continue;
        }
        dfs(num);
    }
}

int main() {

    int n, m;
    cin>> n >> m;
    virus.assign(n+1, vector<int>());
    visited.assign(n+1, false);

    while(m--) {
        int a, b;
        cin >> a >> b;
        virus[a].push_back(b);
        virus[b].push_back(a);
    }

    dfs(1);
    cout << result-1 <<'\n';
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> aList;
vector<bool> visited;
int depth=0;
void dfs(int node) {
    if(visited[node]) {
        return;
    }
    visited[node] = true;
    depth++;
    for(int i=0; i<aList[node].size(); i++) {
        dfs(aList[node][i]);
    }

}

void dfsStack() {
    stack<int> st;
    int node=1;

    st.push(node);
    visited[node] = true;

    while(!st.empty()) {
        node = st.top();
        st.pop();
        for(int i=0; i<aList[node].size(); i++) {
            if(!visited[aList[node][i]]) {
                st.push(aList[node][i]);
                visited[aList[node][i]] = true;
                depth++;
            }
        }
    }


}

int main() {
    int n, m;
    cin>>n>>m;
    aList.assign(n+1, vector<int>());
    visited.assign(n+1, false);

    for(int i=0; i<m; i++) {
        int a,b;
        cin>> a>>b;
        aList[a].push_back(b);
        aList[b].push_back(a);
    }

    dfs(1);
    dfsStack();
    cout<<depth-1;
    return 0;

}*/
