#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> papers){

}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> papers(n, vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>papers[i][j];
        }
    }

    cout<<solution(papers);
}