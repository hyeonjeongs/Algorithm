#include<iostream>
#include<vector>

using namespace std;

int modCase(int a, int b, int c) {
	int x, y, z;
	int cnt = 0;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				x = i % j;
				y = j % k;
				z = k % i;
	
				if (x == y && y==z && z==x){
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << modCase(a, b, c) << '\n';
	}

	return 0;
}