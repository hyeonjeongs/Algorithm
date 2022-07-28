#include<iostream>
#include<vector>

using namespace std;

vector<bool> check;
vector<int> num;
int n, m;
void backTracking(int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) 
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			num[index] = i;
			check[i] = true;
			backTracking(index + 1);
			check[i] = false; //원래 상태로 돌려놓기
		}
	}
}

int main() {
	cin >> n >> m;

	check.assign(n+1, false);
	num.assign(m, 0);

	backTracking(0);
}