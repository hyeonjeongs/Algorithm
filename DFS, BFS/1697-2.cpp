#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5;
int n, k;
int bfs() {
    queue<int> que;
    que.push(n);
    vector<int> visited(SIZE+1, 0);
    visited[n]=1;
    int result = 1e5+1;

    while(!que.empty()) {
        int node = que.front();
        que.pop();
        if(node == k) {
            result = min(result, visited[node]-1);
            break;
        }
        vector<int> child = {node-1, node+1, node*2};

        for(int i=0; i<3; i++) {

            if(child[i]<0 || child[i]>SIZE || visited[child[i]]>0) {
                continue;
            }
            visited[child[i]] = visited[node]+1;
            que.push(child[i]);
        }
    }
    return result;
}
int main() {

    cin >> n >> k;
    cout << bfs() << '\n';

    return 0;
}