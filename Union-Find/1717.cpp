#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;

//find
int findParent(int node) {
    if (parent[node] < 0) { // 값 음수면 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//union
void unionType(int a, int b) {
    int rx = findParent(a);
    int ry = findParent(b);

    if (rx == ry) //이미 같은 집합에 있는 경우
        return;
    else if (parent[rx] < parent[ry]) { //새로운 루트 rx
        parent[rx] += parent[ry];
        parent[ry] = rx;
    }
    else { //새로운 루트 ry
        parent[ry] += parent[rx];
        parent[rx] = ry;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int type, a, b;
    cin >> n >> m;
    parent.assign(n + 1, -1); //weighted union find

    while (m--) {
        cin >> type >> a >> b;

        if (type == 0)
            unionType(a, b);

        if (type == 1) {
            if (findParent(a) == findParent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;

}