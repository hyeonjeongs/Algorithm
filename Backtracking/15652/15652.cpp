#include<iostream>
#include<vector>

using namespace std;

int n, m;

vector<int> num;
void backTracking(int cnt, int start) {
	if (cnt == m) {// 기저조건:선택한 개수와 m 같으면 출력
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		num[cnt] = i;
		backTracking(cnt + 1, i);
	}

}

int main() {
	cin >> n >> m;
	num.assign(m, 0);
	backTracking(0, 1);

	return 0;
}