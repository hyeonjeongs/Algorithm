#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;

int maxNum(int p) {
	int cnt = 0;

	for (int i = 0; i < a.size(); i++) {
		if (p >= 200)
			return cnt;
		if (p < 200) {
			p += a[i];
			cnt++;
		}

	}
	return cnt;
}

int main() {
	int p, n;
	cin >> p >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	sort(a.begin(), a.end());

	cout << maxNum(p);

	return 0;
}