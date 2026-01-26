#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> parents;
vector<bool> visited;
struct NODE {
    int a;
    int b;
    int price;

    bool operator<(const NODE &other) const {
        if (price != other.price) {
            return price < other.price;
        }
        if (a != other.a) {
            return a < other.a;
        }
        return b < other.b;
    }
};
int findParent(int node) {
    if (parents[node] < 0) {
        return node;
    }
    return parents[node] = findParent(parents[node]);
}
bool unions (int a, int b) {
    int nodeA = findParent(a);
    int nodeB = findParent(b);
    if (nodeA == nodeB) {
        return false;
    } else if (parents[nodeA] < parents[nodeB]) {
        parents[nodeA] += parents[nodeB];
        parents[nodeB] = nodeA;
    } else {
        parents[nodeB] += parents[nodeA];
        parents[nodeA] = nodeB;
    }
    return true;
}

int main() {

    cin >> n >> m;
    vector<vector<int>> lines(n+1, vector<int>(n+1, 0));
    vector<NODE> nodes;
    parents.assign(n+1, -1);
    visited.assign(n+1, false);

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lines[a][b] = c;
        lines[b][a] = c;
        nodes.push_back({a, b, c});
    }
    sort(nodes.begin(), nodes.end());

    int total = 0;

    for (int i=0; i<nodes.size(); i++) {
        NODE nums = nodes[i];
        if (nums.a == nums.b) {
            continue;
        }
        if (unions(nums.a, nums.b)) {
            total += nums.price;
        }

    }
    cout << total << '\n';
    return 0;

}