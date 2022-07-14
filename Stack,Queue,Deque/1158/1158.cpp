#include<iostream>
#include<vector>
#include<queue>

using namespace std;
queue<int> result;
int main() {
	int k, n;

	cin >> n >> k;
	int num;

	for (int i = 1; i <= n; i++) {
		result.push(i);
	}

	cout << "<";

	while (result.size() > 1) {
		for (int i = 1; i < k; i++) {
			num = result.front();
			result.pop();
			result.push(num);
		}
		cout << result.front()<<", ";
		result.pop();
	}
	cout << result.front() << ">";

	return 0;

}

