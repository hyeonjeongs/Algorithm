#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void makeResult(vector<int> result, int n){
    stack<int> st;
    vector<char> stack_result;
    int index =0;

    for(int i=1; i<=n; i++) {
        st.push(i);
        stack_result.push_back('+');

        while(!st.empty() && st.top()==result[index]){
            st.pop();
            stack_result.push_back('-');
            index++;
        }
    }

    if(st.empty()) {
        for(int i=0; i<stack_result.size(); i++){
            cout<<stack_result[i]<<'\n';
        }
        return;
    }
    cout<<"NO"<<'\n';
}


int main() {

    int n;
    cin>>n;
    vector<int> result(n,0);

    for(int i=0; i<n; i++){
        cin>>result[i];
    }

    makeResult(result, n);

    return 0;
}