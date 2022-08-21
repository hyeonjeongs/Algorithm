#include<iostream>
#include<vector>

using namespace std;

vector<int> a;
int energy = 0;

void airpotLink(int n) {
	int back = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			if (energy + 2 >= 100) {
				energy = 0;
				a[i] = -1;
				back = 0;
			}
			else {
				energy += 2;
				back = 2;
			}
		}
		else {
			if (energy + back*2 >= 100) {
				energy = 0;
				a[i] = -1;
				back = 0;
			}
			else {
				energy += back * 2;
				back = back * 2;
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	a.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	airpotLink(n);
	cout << energy << '\n';

	return 0;
}