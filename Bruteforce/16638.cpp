#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long result = LLONG_MIN;

long long calc(vector<int> nums, vector<char> opts) {
    vector<int> new_num;
    vector<char> new_opt;
    long long current = nums[0];
    for (int i=0; i<opts.size(); i++) {
        if (opts[i] == '*') {
            current *= nums[i+1];
        } else {
            new_opt.push_back(opts[i]);
            new_num.push_back((int)current);
            current = nums[i+1];
        }
    }
    new_num.push_back((int)current);
    long long answer = new_num[0];
    for (int i=0; i<new_opt.size(); i++) {
        if (new_opt[i] == '+') {
            answer += new_num[i+1];
        } else {
            answer -= new_num[i+1];
        }
    }
    return answer;
}

void dfs (vector<int> nums, vector<char> opts, int index) {
    result = max(result, calc(nums, opts));
    for (int i=index; i<opts.size(); i++) {
        int calc_num=nums[i];

        if (opts[i] == '+') {
            calc_num += nums[i+1];
        } else if (opts[i] == '-') {
            calc_num -= nums[i+1];
        } else {
            calc_num *= nums[i+1];
        }
        vector<int> nnums = nums;
        vector<char> oopts = opts;
        nnums.erase(nnums.begin()+i, nnums.begin()+i+2);
        oopts.erase(oopts.begin() + i);
        nnums.insert(nnums.begin() + i, calc_num);

        long long maxs = calc(nnums, oopts);
        result = max(maxs, result);

        dfs(nnums, oopts, i+1);
    }

}
int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    vector<int> num;
    vector<char> opt;

    for (int i=0; i<str.size(); i++) {
        if (isdigit(str[i])) {
            num.push_back(str[i]-'0');
        } else {
            opt.push_back(str[i]);
        }
    }
    result = max(result, calc(num, opt));
    dfs(num, opt, 0);

    cout << result <<'\n';
    return 0;
}