#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;
int main() {
	int num;
	cin >> num;
	arr.assign(num, 0);
	
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	

	for (int i = 0; i < num; i++) {
		cout << arr[i]<<'\n';
	}
}