#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a;
vector<int> b;


int main() {
	int n, result=0;
	cin >> n;

	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	
	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}
	cout << result;

	return 0;
}