#include<iostream>
#include<stack>

using namespace std;

stack<int> num;
void resultNum() {
	int sum = 0;
	int size = num.size();
	for (int i = 0; i < size; i++) {
		sum += num.top();
		num.pop();
	}
	cout << sum;
}

int main() {

	int k, n;
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n == 0) {
			num.pop();
		}
		else {
			num.push(n);
		}
	}

	resultNum();
	
	return 0;
}