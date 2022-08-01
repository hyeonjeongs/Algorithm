#include<iostream>
#include<vector>

using namespace std;

void minNum(int n) {
	int five=0, three=0;
	int num;

	five = n / 5; //최대 5의 개수

	while (1) {
		if (five < 0) {
			num = -1;
			break;
		}

		if ((n - (five * 5)) % 3 == 0) {
			three = (n - (five * 5)) / 3;
			num = three + five;
			break;
		}

		five--;
	}

	cout << num;
}

int main() {
	int n;
	cin >> n;

	minNum(n);

	return 0;
}