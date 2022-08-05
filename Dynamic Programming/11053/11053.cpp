#include<iostream>
#include<vector>

using namespace std;

vector<int> num;
vector<int> dp;
int maxLength(int n) {
	int maxN = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) 
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxN = max(maxN, dp[i]);
	}
	return maxN;
}
int main() {
	int n;
	cin >> n;
	num.assign(n, 0);
	dp.assign(1001, 1);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	cout << maxLength(n);

	return 0;
}