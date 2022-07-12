#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> words;

bool cmp(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main() {
	int num;
	string word;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> word;
		words.push_back(word);
	}

	sort(words.begin(), words.end(), cmp);

	cout << words[0] << '\n';
	for (int i = 1; i < num; i++) {
		if (words[i] == words[i - 1])
			continue;
		cout << words[i] << '\n';
	}
}




//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//vector<pair<int, int>> arr;
//
//bool cmp(pair<int, int> a, pair<int, int> b) {//사용자 정의
//	if (a.second == b.second)
//		return a.first < b.first; //입력한 숫자는 오름차순으로
//	return a.second < b.second;
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL); cout.tie(NULL);
//	int num;
//	cin >> num;
//
//	for (int i = 0; i < num; i++) {
//		int x, y;
//		cin >> x >> y;
//		arr.push_back(pair<int, int>(x, y));
//	}
//
//	sort(arr.begin(), arr.end(), cmp);
//
//
//	for (int i = 0; i < num; i++) {
//		cout << arr[i].first << ' ' << arr[i].second << '\n';
//	}
//}