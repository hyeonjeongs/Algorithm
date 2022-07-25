#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> tree;
void maxTree(long long n, long long m) {
	sort(tree.begin(), tree.end());
	long long start = 0;
	long long end = tree.back();
	long long height;
	long long result = 0;
	while (start <= end) {
		height = (start + end) / 2;
		long long total = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] > height)
				total += (tree[i] - height);
		}
		if (total >= m) {
			result = height;
			start = height + 1;
		}
		else if (total < m)
			end = height - 1;
	
	}

	cout << result;
}

int main() {
	long long n, m;
	cin >> n >> m;
	long long total = n;
	while (total--) {
		long long num;
		cin >> num;
		tree.push_back(num);
	}

	maxTree(n, m);

	return 0;
}