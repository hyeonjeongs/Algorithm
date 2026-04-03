# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;
typedef pair<int, int> pi;


int main() {
    int n;
    cin>>n;
    vector<int> alpha(27,0); // (인덱스, 개수)

    for (int i=0; i<n; i++) {
        string input;
        cin >> input;
        int num=1;
        for (int j=input.size()-1; j>=0; j--) {
            alpha[input[j]-'A'] += num;
            num*=10;
        }
    }
    sort(alpha.begin(), alpha.end(), greater<>());

    int total = 0;
    int number = 9;
    for (int i=0; i<alpha.size(); i++) {
        if (alpha[i] ==0) {
            break;
        }
        total += number * alpha[i];
        number--;
    }
    cout << total << '\n';
    return 0;
}