#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

int findParent(int node) {
    if (parents[node]<0) {
        return node;
    }
    return parents[node] = findParent(parents[node]);
}
bool unionNode(int a, int b) {
    int nodeA = findParent(a);
    int nodeB = findParent(b);
    if (nodeA == nodeB) {
        return false;
    }

    if (parents[nodeA] < parents[nodeB]) {
        parents[nodeA] += parents[nodeB];
        parents[nodeB] = nodeA;
    } else {
        parents[nodeB] += parents[nodeA];
        parents[nodeA] = nodeB;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n>> m;
    int result =0;
    parents.assign(n+1, -1);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a>> b;
        if (!unionNode(a, b)) {
            result = i+1;
            break;
        }
    }
    cout << result << '\n';

    return 0;
}