#include<iostream>
#include<vector>
using namespace std;

vector<int> a;

void greedyAl(int n, int s) {
	for (int i = 0; i < n; i++)
	{
		if (s <= 0)
			break;
		int num = a[i];
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (s - (j - i) < 0)
				break;
			
			if (num < a[j])
			{
				num = a[j];
				index = j;
			}
			
		}
		for (int j = index; j > i; j--)
			swap(a[j], a[j - 1]);
		s -= (index - i);
		
	}
}
int main() {
	int n, s;

	cin >> n;
	a.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> s;

	greedyAl(n, s);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}