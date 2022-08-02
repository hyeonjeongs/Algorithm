#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, string> ci;

vector<ci> members;
bool cmp(const ci& a, const ci& b) {
	return a.first < b.first;
}
int main() {
	int n;
	cin >> n;

	members.assign(n,ci(0," "));
	for (int i = 0; i < n; i++) {
		cin >> members[i].first >> members[i].second;
	}

	stable_sort(members.begin(), members.end(), cmp);

	for (int i = 0; i < n; i++) 
		cout << members[i].first << " " << members[i].second << '\n';
	
	return 0;
}