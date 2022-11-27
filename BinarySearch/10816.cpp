#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> card;
vector<int> result;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        card.push_back(num);
    }

    sort(card.begin(), card.end());
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) << " ";

    }

    return 0;
}