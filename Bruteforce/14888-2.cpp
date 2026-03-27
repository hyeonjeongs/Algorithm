# include <iostream>
# include <vector>

using namespace std;
vector<int> opt;
vector<int> arr;
int mins = 1e9;
int maxs = -1e9;
int makeNumber(int opts, int a, int b) {
    if (opts==0) {
        return a+b;
    } else if (opts ==1) {
        return a-b;
    } else if (opts ==2) {
        return a*b;
    } else {
        return a/b;
    }

}
void makeNums(int current, int idx) {
    if (idx>=arr.size()) {
        mins = min(mins, current);
        maxs = max(maxs, current);
        return;
    }
    for (int i=0; i<4; i++) {
        if (opt[i]>0) {
            opt[i]--;
            makeNums(makeNumber(i, current, arr[idx]), idx+1);
            opt[i]++;
        }
    }
}
int main() {
    int n;
    cin >> n;
    arr.assign(n, 0);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<4; i++) {
        int num;
        cin >> num;
        opt.push_back(num);
    }
    makeNums(arr[0], 1);

    cout << maxs << '\n' << mins << '\n';
    return 0;
}




/*# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

char opt[] = {'+', '-', '*', '/'};
int makeNumber(char opts, int a, int b) {
    if (opts=='+') {
        return a+b;
    } else if (opts == '-') {
        return a-b;
    } else if (opts =='*') {
        return a*b;
    } else {
        return a/b;
    }

}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<char> numbers;
    vector<int> orders;
    for (int i=0; i<4; i++) {
        int input;
        cin >> input;
        for (int j=0; j<input; j++) {
            orders.push_back(numbers.size());
            numbers.push_back(opt[i]);
        }
    }
    int mins = 1e9 +1;
    int maxs = -(1e9 +1);
    do {
        int current = arr[0];
        for (int i=0; i<orders.size(); i++) {
            current = makeNumber(numbers[orders[i]], current, arr[i+1]);
        }
        mins = min(mins, current);
        maxs = max(maxs, current);
    } while (next_permutation(orders.begin(), orders.end()));

    cout << maxs << '\n' << mins << '\n';

    return 0;
}*/