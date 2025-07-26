#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int findParent(int node) {
    if(parent[node]== node) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}
void unionParent(int a, int b) {

    int parentA = findParent(a);
    int parentB = findParent(b);

    if(parentB < parentA) {
        parent[parentA] = parentB;
    } else if(parentB > parentA) {
        parent[parentB] = parentA;
    } else {
        parent[parentA] = 0;
        parent[parentB] = 0;
    }
}
int main() {
    int n, m;
    int cases = 1;
    while(1) {

        cin >> n >>m;
        if(n==0 && m==0) {
            break;
        }
        parent.assign(n+1, 0);
        for(int i=0; i<parent.size(); i++) {
            parent[i] = i;
        }
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            unionParent(a, b);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(parent[i] == i) {
                cnt++;
            }
        }

        cout << "Case " << cases;
        cases++;
        if(cnt==0) {
            cout << ": No trees."<< '\n';
        } else if(cnt==1) {
            cout << ": There is one tree." << '\n';
        } else {
            cout << ": A forest of " << cnt << " trees." << '\n';
        }
    }
}