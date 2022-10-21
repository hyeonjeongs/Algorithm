#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[100001];
int visited[100001] = {0, };
int parent[100001];

void DFS(int v) {
    visited[v] = 1;
    for(int i=0; i<tree[v].size(); i++)
        if(!visited[tree[v][i]]) {
            parent[tree[v][i]] = v;
            DFS(tree[v][i]);
        }
}

int main() {
    int N, a, b;
    cin >> N;
    for(int i=0; i<N-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);
    for(int i=2; i<=N; i++)
        cout << parent[i] << '\n';

    return 0;
}