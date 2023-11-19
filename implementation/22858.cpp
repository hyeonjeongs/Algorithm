#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int d[10001];
    int s[10001];
    int p[10001];

    for(int i=1; i<=n; i++){
        cin>>s[i];
    }
    for(int i=1; i<=n; i++){
        cin>>d[i];
    }

    for(int i=0; i<k; i++) {
        for(int j=1; j<=n; j++) {
            p[d[j]] = s[j];
        }
        memcpy(s, p, sizeof(p));
    }

    for(int i=1;i<=n; i++) {
        cout<< p[i] <<" ";
    }

    return 0;
}