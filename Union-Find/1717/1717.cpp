#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;

//find
int findParent(int node) {
	if (parent[node] < 0) {
		return node;
	}
	return parent[node] = findParent(parent[node]);
}

//union
void unionType(int a, int b) {
	int rx = findParent(a);
	int ry = findParent(b);

	if (rx == ry)
		return;
	else if (parent[rx] < parent[ry]) {
		parent[rx] += parent[ry];
		parent[ry] = rx;
	}
	else {
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
	parent.assign(n + 1, -1); //weighted union find ¿¬»ê

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