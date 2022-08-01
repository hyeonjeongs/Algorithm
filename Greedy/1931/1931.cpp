#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> ci;
vector<ci> meeting;

bool cmp(const ci &a, const ci &b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int meetingCnt(int n) {
	int cnt = 1;
	int end = meeting[0].second; //회의 끝나는 시간
	for (int i = 1; i < n; i++) {
		if (end <= meeting[i].first) {
			cnt++;
			end = meeting[i].second;
		}
	}

	return cnt;
}
int main() {
	int n;

	cin >> n;
	meeting.assign(n, ci(0, 0));

	for (int i = 0; i < n; i++) {
		cin >> meeting[i].first >> meeting[i].second;
	}

	sort(meeting.begin(), meeting.end(), cmp);

	cout << meetingCnt(n);

	return 0;
}