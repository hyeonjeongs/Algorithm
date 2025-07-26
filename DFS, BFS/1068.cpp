#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> tree;
int result = 0;

void bfs(int deletes) {
    queue<int> que;
    que.push(deletes);

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i = 0; i < tree[node].size(); i++) {
            que.push(tree[node][i]);
        }
        tree[node].clear();

    }
    for(int i=0; i<tree.size(); i++) {
        for(int j=0; j<tree[i].size(); j++) {
            if(deletes == tree[i][j]) {
                tree[i].erase(tree[i].begin() + j);
            }
        }
    }
}

void findNode(int root, int deletes) {
    if (tree[root].size() == 0 && root != deletes) {
        result++;
        return;
    }

    for (int i = 0; i < tree[root].size(); i++) {
        if (tree[root][i] != deletes) {
            findNode(tree[root][i], deletes);
        }

    }
}

int main() {
    int n;
    cin >> n;
    tree.assign(n, vector<int>());
    int root = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input == -1) {
            root = i;
        } else {
            tree[input].push_back(i);
        }
    }
    int delete_node;
    cin >> delete_node;

    bfs(delete_node);
    findNode(root, delete_node);
    cout << result << '\n';

    return 0;
}