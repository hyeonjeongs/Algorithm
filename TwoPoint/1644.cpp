#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

bool findNum(int n) {
    if (n<=1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i ==0) return false;
    }
    return true;
}

int twoPoint(int n, const vector<int>& sums) {
    int left = 0, right = 1;
    int answer = 0;

    while (left <sums.size() && right < sums.size()) {
        int sum = sums[right] - sums[left];

        if (sum < n) {
            right++;
        } else if (sum > n) {
            left++;
            if (left == right) right++;
        } else {
            answer++;
            left++;
            if (left == right) right++;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;

    if (n <2) {
        cout << 0;
        return 0;
    }

    for (int i=2; i <= n; i++) {
        if (findNum(i)) nums.push_back(i);
    }

    vector<int> sums(nums.size() + 1, 0);
    for (int i = 1; i <=nums.size(); i++) {
        sums[i] = sums[i-1] + nums[i-1];
    }

    cout << twoPoint(n, sums);
    return 0;
}
