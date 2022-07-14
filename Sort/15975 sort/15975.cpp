#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;

vector<int> color[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	long distance = 0;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int locate, colors;
		cin >> locate >> colors;
		color[colors].push_back(locate);
	}



	for (int i = 1; i < MAX; i++) {
		if (color[i].empty())
			continue;

		sort(color[i].begin(), color[i].end());

		distance += color[i][1] - color[i][0];

		for (int j = 1; j < color[i].size() - 1; j++) {
			int x = color[i][j];
			distance += min(x - color[i][j - 1], color[i][j + 1] - x);
		}
		int end = color[i].size() - 1;
		distance += color[i][end] - color[i][end - 1];
	}

	cout << distance << '\n';
}
