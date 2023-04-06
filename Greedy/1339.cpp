#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
/*
 *
 * ABC
 * BCA
 * 이러한 경우 A, B 둘중 어떤걸 더 높은거 줘야할지 생각해야함 -> 이부분 처음에 생각못함
 */

//내림차순
bool cmp(int &a, int &b) {
    return a > b;
}

int wordNum(vector<int> &alpha){
    int num = 9;
    int result = 0;
    for (int i = 0; i < 26;i++) {
        if (alpha[i] == 0)
            break;
        result += alpha[i] * num--;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> alpha(27,0);
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        int num = 1;
        for (int j = input.length()-1; j >= 0; j--) {
            alpha[input[j]-'A'] += num;
            num *= 10;
        }
    }

    sort(alpha.begin(), alpha.end(),cmp);

    cout<<wordNum(alpha)<<'\n';

    return 0;
}