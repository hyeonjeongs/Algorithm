#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
    string name;
    int korean, english, math;
};

bool cmp(const info &a, const info &b) {
    if (a.korean != b.korean)
        return a.korean > b.korean;
    if (a.english != b.english)
        return a.english < b.english;
    if (a.math != b.math)
        return a.math > b.math;
    return a.name < b.name;
}

int main() {
    int n;
    vector<info> score;

    cin >> n;
    score.assign(n,{});
    for (int i = 0; i < n; i++) {
        cin >> score[i].name >> score[i].korean >> score[i].english >> score[i].math;
    }

    sort(score.begin(), score.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << score[i].name << '\n';
    }
    return 0;
}