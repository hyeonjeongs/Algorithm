#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<char> tech;
stack<char> st;

int techTotal(int n) {
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (tech[i] == 'S' || tech[i] == 'L') {
			st.push(tech[i]);
		}
		else if (tech[i] == 'K') {
			if (st.top() == 'S') {
				num++;
				st.pop();
			}
		}
		else if (tech[i] == 'R') {
			if (st.top() == 'L') {
				num++;
				st.pop();
			}
		}
		else {
			num++;
		}
	}

	return num;
}

int main() {
	int n;
	cin >> n;
	tech.assign(n, 0);

	
	for (int i = 0; i < n; i++) {
		cin >> tech[i];
	}

	cout<<techTotal(n);

	return 0;
}