#include<iostream>
#include<stack>

using namespace std;

stack<char> s;
int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (s.empty() || str[j] == '(') {
				s.push(str[j]);
			}
			else if(str[j]==')' && s.top()=='(') {
				s.pop();
			}
		}
		if (s.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		while (!s.empty()) s.pop();
	}

	return 0;
}