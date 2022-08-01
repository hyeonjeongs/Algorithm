#include<iostream>
#include<vector>

using namespace std;

vector<int> coin;
void coinNum(int n, int k) {
	int cnt = 0; //동전 개수
	for (int i = n - 1; i >= 0; i--) {
		if (k == 0)
			break;
		cnt += k / coin[i];
		k = k % coin[i]; //나머지 돈
	}
	cout << cnt;
}
int main() {
	int n, k;
	cin >> n >> k;
	coin.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	coinNum(n, k);
	return 0;
}