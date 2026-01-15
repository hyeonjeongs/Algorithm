#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct DATE {
    int sm;
    int sd;
    int em;
    int ed;
    bool operator<(const DATE& other) const {
        if (sm==other.sm) {
            return sd < other.sd;
        }
        return sm < other.sm;
    }
};
vector<DATE> dates;
int result=1e6;
bool checks (int index,int currents) {
    DATE current = dates[currents];
    DATE prior = dates[index];
    bool is_next = false;
    if (prior.em < current.em || (prior.em == current.em && prior.ed <current.ed)) {
        if (prior.em == current.sm && prior.ed>= current.sd) {
            is_next = true;
        }
        if (prior.em > current.sm) {
            is_next = true;
        }
    }

    return is_next;
}

void dfs(int index, int cnt) {

    if (dates[index].em==12) {

        result = min(cnt, result);
        return;
    }
    for (int i=index+1; i<dates.size(); i++) {

        if (checks(index, i)){
            dfs(i, cnt+1);
        }
    }
}
int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >>d;
        dates.push_back({a, b, c, d});
    }

    sort(dates.begin(), dates.end());


    int index =0;
    while (1) {
        int sm = dates[index].sm;

        if (sm<3) {
            dfs(index, 1);
        } else {
            break;
        }
        index++;
    }

    if (result == 1e6) {
        result = 0;
    }
    cout << result << '\n';

    return 0;
}