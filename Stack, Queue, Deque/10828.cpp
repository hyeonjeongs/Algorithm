#include <iostream>
#include <stack>

using namespace std;

void stackFunc(string order, stack<int> &st){
    int n;
    if(order == "push"){
        cin>>n;
        st.push(n);
        return;
    }
    if(order == "pop"){
        if(st.empty()){
            cout<<"-1\n";
        }else{
            cout<< st.top()<<'\n';
            st.pop();
        }
        return;
    }
    if(order=="size"){
        cout<<st.size()<<'\n';
        return;
    }
    if(order=="empty"){
        if(st.empty())
            cout<<"1\n";
        else
            cout<<"0\n";
        return;
    }
    if(order=="top"){
        if(st.empty())
            cout<<"-1\n";
        else{
            cout<<st.top()<<"\n";
        }
        return;
    }
}

int main() {
    int n;
    cin >> n;
    stack<int> st;

    string input;
    for(int i=0; i<n; i++){
        cin>>input;
        stackFunc(input, st);
    }

    return 0;
}
