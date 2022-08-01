#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minAtm(int n, vector<int> atm) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += atm[j];
		}
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> atm(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> atm[i];
	}

	sort(atm.begin(), atm.end());

	cout << minAtm(n, atm);

	return 0;
}