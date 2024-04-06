#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int b, c;
    cin >>n;
    vector<int> students(n,0);

    for(int i=0; i<n; i++){
        cin>>students[i];
    }

    cin>>b>>c;
    long long cnt=n;
    for(int i=0; i<n; i++) {
        students[i] -= b;
        if(students[i]<=0)
            continue;
        cnt += students[i]/c;
        if(students[i]%c)
            cnt++;
    }

    cout<< cnt;
    return 0;
}