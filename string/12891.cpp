#include <iostream>
#include <vector>

using namespace std;
int a,c,g,t;
int main() {
    int s, p;
    cin >> s >> p;
    string str;
    cin >> str;
    vector<int> counts(30, 0);

    cin >> a >> c >> g >> t;
    int result =0;

    int left = 0, right = p-1;

    for (int i=0; i<p; i++) {
        int num = str[i] - 'A';
        counts[num]++;
    }

    while (right<s) {

        if (counts[0]>=a && counts[2]>=c && counts[6]>=g && counts[19]>=t) {
            result++;
        }
        int left_str = str[left]-'A';
        counts[left_str]--;
        left++;
        right++;
        int right_str = str[right]-'A';
        counts[right_str]++;
    }

    cout << result;

    return 0;
}