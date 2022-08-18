#include<iostream>
#include<vector>

using namespace std;

vector<bool> truth;
vector<int> parent;

int findParent(int node) {
	if (parent[node] < 0)
		return node;
	return parent[node] = findParent(parent[node]);
}

void unionParent(int a, int b) {
	int ra = findParent(a);
	int rb = findParent(b);

	if (ra == rb) //같은 집합인 경우
		return;
	if (truth[ra] || truth[rb]) 
		truth[ra] = truth[rb] = true;
	if (parent[ra] < parent[rb]) {
		parent[ra] += parent[rb];
		parent[rb] = ra;
	}
	else {
		parent[rb] += parent[ra];
		parent[ra] = rb;
	}

}

int partyNum(vector<int> group){
	int cnt = 0;
	for (int i = 0; i < group.size(); i++) {
		int parent = findParent(group[i]);
		if (!truth[parent])
			cnt++;
	}

	return cnt;
}

int main() {
	int n, m;
	int know, p;
	cin >> n >> m;
	truth.assign(n + 1, false);
	parent.assign(n + 1, -1);

	cin >> know;
	while (know--) { // 진실아는 사람 입력
		cin >> p;
		truth[p] = true;
	}

	int cnt, firstP, person;
	vector<int> group;
	while (m--) {
		cin >> cnt >> firstP;
		group.push_back(firstP);

		for (int i = 1; i < cnt; i++) {
			cin >> person;
			unionParent(firstP, person);
		}
	}

	cout << partyNum(group);

	return 0;
}