#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b) {//사용자 정의
	if (a.second == b.second)
		return a.first < b.first; //입력한 숫자는 오름차순으로
	return a.second < b.second;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back(pair<int,int>(x,y));
	}

	sort(arr.begin(), arr.end(),cmp);


	for (int i = 0; i < num; i++) {
		cout << arr[i].first << ' ' << arr[i].second<<'\n';
	}
}