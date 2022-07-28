#include<iostream>
#include<vector>

using namespace std;

void permutation(int n) {
	int cnt = 0;
	if (n < 100) {
		cout << n;
		return;
	}
	else {
		cnt = 99;

		for (int i = 100; i <= n; i++) {
			int hun = i / 100;
			int ten = (i / 10) % 10;
			int one = i % 10;

			if ((hun - ten) == (ten - one))
				cnt++;
		}
	}
	cout << cnt;
}

int main() {
	int n;
	cin >> n;

	permutation(n);
	return 0;
}