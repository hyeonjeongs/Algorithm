#include <iostream>
#include <vector>

using namespace std;
vector<int> nodes;
int findParent(int node) {

    if(nodes[node] <0) {
        return node;
    }

    return nodes[node] = findParent(nodes[node]);
}
void unionNode(int a, int b) {

    int a_parent = findParent(a);
    int b_parent = findParent(b);
    if(a_parent == b_parent) {
        return;
    } else if(nodes[a_parent] < nodes[b_parent]) {
        nodes[a_parent] += nodes[b_parent];
        nodes[b_parent] = a_parent;
    } else {
        nodes[b_parent] += nodes[a_parent];
        nodes[a_parent] = b_parent;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    nodes.assign(n+1, -1);

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==0) {
            unionNode(b, c);
        } else {
            if(findParent(b) == findParent(c)) {
                cout << "YES"<<'\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}