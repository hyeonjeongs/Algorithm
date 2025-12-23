#include <iostream>
#include <vector>

using namespace std;
int result = 0;
int sizes;
vector<int> alpha;
void checkWord(string words) {
    vector<int> copys = alpha;
    int nums = 0;
    int remain = 0;

    for (int i=0; i<words.length(); i++) {
        int index = words[i] - 'A';
        if (copys[index] >0) {
            copys[index]--;
            nums++;
        } else {
            remain++;
        }
    }

    if (nums == sizes && remain <=1) {
        result++;
    } else if (nums+1 == sizes) {
        if (remain <=1) {
            result++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string word;
    cin >> n;
    cin >> word;
    alpha.assign(27, 0);
    sizes = word.length();
    for (int i=0; i<word.length(); i++) {
        int index = word[i] - 'A';
        alpha[index]++;
    }

    for (int i=1; i<n; i++) {
        string input;
        cin >> input;
        checkWord(input);
    }
    cout << result << '\n';

    return 0;
}