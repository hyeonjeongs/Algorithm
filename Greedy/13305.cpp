#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
vector<ll> road;
vector<ll> city;
ll minCost(int n) {
    ll totCost = 0;
    ll curCost = city[0];

    for (int i = 0; i < n-1; i++) {
        if (curCost > city[i])
            curCost = city[i];
        totCost += curCost * road[i];
    }
    return totCost;
}

int main() {
    int n;
    cin >> n;
    road.assign(n - 1, 0);
    city.assign(n, 0);

    for (int i = 0; i < n - 1; i++)
        cin >> road[i];
    for (int i = 0; i < n; i++)
        cin >> city[i];

    cout << minCost(n);

    return 0;
}