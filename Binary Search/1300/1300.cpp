#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;
void binarySearch(int left, int right) {
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 1; i <= n; i++)
			cnt += min(mid / i, n);
		if (cnt >= k) {
			result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;

	}
	cout << result << '\n';
}

int main() {
	cin >> n >> k;

	binarySearch(1, k);

	return 0;
}