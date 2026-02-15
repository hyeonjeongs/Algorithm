#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s, p;
    cin >> s >> p;
    string str;
    cin >> str;
    vector<int> nums(26,0);
    vector<int> cnt(26, 0);
    cin >> nums['A'-'A'] >> nums['C'-'A'] >> nums['G'-'A'] >>nums['T'-'A'];
    int answer =0;
    int left=0, right =0;
    for (int i = 0; i < p; i++) {
        cnt[str[i] - 'A']++;
    }
    right = p-1;

    while (right<s) {
        if (cnt[0] >=nums[0] && cnt[2] >= nums[2] && cnt[6] >=nums[6] && cnt[19]>=nums[19]) {
            answer++;
        }
        if (right==s-1) {
            break;
        }
        cnt[str[left++]-'A']--;
        cnt[str[++right]-'A']++;

    }
    cout << answer << '\n';
    return 0;
}