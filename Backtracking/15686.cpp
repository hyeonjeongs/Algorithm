#include <iostream>
#include <vector>
#include <algorithm>
// 3:40
using namespace std;
typedef pair<int,int> pi;

int n, m;
vector<pi> city;
vector<pi> chicken;
vector<bool> check;
int min_sum = 1e6;

void backTracking(int index, int cnt) {

    if(cnt ==m) {
        int sum =0;
        for(int i=0; i<city.size(); i++){
            int current = 1e4;
            for(int j=0; j<chicken.size(); j++) {
                if(check[j]) {
                    int distance = abs(city[i].first-chicken[j].first) + abs(city[i].second - chicken[j].second);
                    current = min(current, distance);
                }
            }
            sum += current;
        }
        min_sum =min(sum, min_sum);
    }

    for(int i=index; i<chicken.size(); i++) {
        if(check[i])
            continue;
        check[i] = true;
        backTracking(i,cnt+1);
        check[i] = false;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>> n>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int num;
            cin>>num;
            if(num==1) {
                city.push_back({j,i}); // x, y
            }
            if(num==2) {
                chicken.push_back({j,i});
            }
        }
    }
    check.assign(chicken.size(), false);


    backTracking(0,0);
    cout<< min_sum <<'\n';

    return 0;
}