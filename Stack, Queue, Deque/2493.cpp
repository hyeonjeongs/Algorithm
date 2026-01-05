# include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int, int> pi;
int main() {
    int n;
    cin >> n;
    stack<pi> s;
    vector<int> result(n, 0);
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;

        while (!s.empty()) {
            if (s.top().second > num ) {
                cout << s.top().first+1 << ' ';
                break;
            }
            s.pop();
        }
        if (s.empty()) {
            cout << "0 ";
        }
        s.push({i, num});
    }

    return 0;
}











/*# include <iostream>
# include <vector>
# include <stack>

using namespace std;
typedef pair<int, int> pi;

int main() {
    int n;
    cin >> n;
    vector<int> result(n, 0);
    stack<pi> next;
    vector<int> nums;


    for (int i=0; i<n; i++) {
        int input;
        cin >> input;

        while (!next.empty()) {
            if (next.top().second > input) {
                result[i] = next.top().first+1;
                break;
            }
            next.pop();
        }
        if (next.empty()) {
            result[i] = 0;
        }
        next.push({i, input});
    }


    for (int i=0; i<n; i++) {
        cout << result[i]<< ' ';
    }
    return 0;
}*/