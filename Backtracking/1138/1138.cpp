#include<iostream>
#include<vector>

using namespace std;
vector<int> order;
vector<int> higherNum;

void findOrder(int n) {
	for (int i = n - 1; i >= 0; i--) {
		vector<int>::iterator iter = order.begin();
		for (int j = 0; j < higherNum[i]; j++)
			iter++;
		order.insert(iter, i + 1); //해당 위치에 i+1 삽입
	}

	for (int i = 0; i < n; i++)
		cout << order[i] << ' ';

}
int main() {
	int n;
	cin >> n;
	order.assign(n, 0);
	higherNum.assign(n, 0);

	for (int i = 0; i < n; i++) {
		int ord;
		cin >> ord;
		higherNum[i] = ord;
	}
	

	findOrder(n);
}