#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> num;
vector<int> perm;
vector<int> check;

void backTracing(int index){
    if(index==m){
        for(int i=0; i<m; i++){
            cout<<perm[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0; i<n; i++){
        if(!check[i]){
            perm[index] = num[i];
            check[i]= true;
            backTracing(index+1);
            check[i] = false;
        }
    }
}

int main(){
    cin>>n>>m;
    num.assign(n,0);
    check.assign(n,false);
    perm.assign(m,0);

    for(int i=0; i<n; i++){
        cin>> num[i];
    }

    sort(num.begin(), num.end());

    backTracing(0);
    return 0;
}