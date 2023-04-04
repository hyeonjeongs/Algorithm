#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> ink (n, 0);
    vector<long long> viscosity (n, 0);
    for(int i=0; i<n; i++){
        cin>>ink[i];
    }
    for(int i=0; i<n; i++){
        cin>>viscosity[i];
    }

    for(int i=0; i<n; i++){
        cout << upper_bound(viscosity.begin(), viscosity.end(), ink[i])- viscosity.begin() - (i+1) << " ";
    }

    return 0;

}