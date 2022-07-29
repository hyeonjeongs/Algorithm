#include<iostream>
#include<vector>

using namespace std;

vector<int> coin;
int main() {
	int n, k;
	cin >> n >> k;
	coin.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	return 0;
}