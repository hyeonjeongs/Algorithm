#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;
int cnt = 0;

int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

void unionInput(int a, int b) {
	int ra = findParent(a);
	int rb = findParent(b);

	if(ra == rb)
		return;
	if (parent[ra] < parent[rb]) {
		parent[ra] += parent[rb];
		parent[rb] = ra;
	}
	else {
		parent[rb] += parent[ra];
		parent[ra] = rb;
	}

}

void outCnt(int cur, int next) {
	int curParent = findParent(cur);
	int nextParent = findParent(next);

	if (curParent != nextParent)
		cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	parent.assign(n + 1, -1);

	while (m--) {
		int a, b;
		cin >> a >> b;
		unionInput(a, b);
	}

	int curLecture, nextLecture;
	cin >> curLecture;
	while (--n) {
		cin >> nextLecture;
		outCnt(curLecture, nextLecture);
		curLecture = nextLecture;
	}
	cout << cnt;

	return 0;
}