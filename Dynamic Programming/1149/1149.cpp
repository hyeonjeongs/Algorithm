#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> cost;
vector<vector<int>> rgb;
int rgbDp(int n) {
	for (int i = 1; i <= n; i++) {
		rgb[i][0] = cost[i][0] + min(rgb[i - 1][1], rgb[i - 1][2]);
		rgb[i][1] = cost[i][1] + min(rgb[i - 1][0], rgb[i - 1][2]);
		rgb[i][2] = cost[i][2] + min(rgb[i - 1][0], rgb[i - 1][1]);
	}
	
	return min(rgb[n][0], min(rgb[n][1], rgb[n][2]));
}

int main() {
	int n;
	cin >> n;

	cost.assign(n + 1, vector<int>(3, 0));
	rgb.assign(n + 1, vector<int>(3, 0));
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	
	cout << rgbDp(n);

	return 0;
}