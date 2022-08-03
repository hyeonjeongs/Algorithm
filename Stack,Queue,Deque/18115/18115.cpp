#include<iostream>
#include<vector>
#include<deque>

using namespace std;

deque<int> card;
vector<int> stack;

void cardStack(int n) {
	for (int i = 1; i <= n; i++) {
		if (stack[i-1] == 1) 
			card.push_front(i);
		else if (stack[i-1] == 2) {
			if (!card.empty()) {
				int cards = card.front(); //�ӽÿ���
				card.pop_front();
				card.push_front(i);
				card.push_front(cards);
			}
		}
		else 
			card.push_back(i);
	}
}

int main() {
	int n;
	cin >> n;

	stack.assign(n, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> stack[n - i]; //���� �������� �����ϱ�
	}


	cardStack(n);

	while (!card.empty()) {
		cout << card.front() << " ";
		card.pop_front();
	}
	return 0;
}