#include <iostream>
#include <vector>
using namespace std;

vector<bool> truth;
vector<int> parent;

int findParent(int node){
    if(parent[node] <0){
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionNum(int x, int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp){
        return;
    }
    if(truth[xp] || truth[yp]){
        truth[xp] = truth[yp] = true;
    }

    if(parent[xp] < parent[yp]){
        parent[xp] += parent[yp];
        parent[yp]= xp;
    }else{
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}



int foolParty(int m, vector<int> &party){
    int cnt=0;

    for(int i=0; i<m; i++){
        int node = findParent(party[i]);
        if(!truth[node]){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int n, m, tr;
    cin>>n>>m>>tr;

    truth.assign(n+1,false);
    parent.assign(n+1, -1);


    vector<int> party;

    int input;
    for(int i=0; i<tr; i++){
        cin>>input;
        truth[input] = true; // 아는 사람
    }

    int first_person, person;
    for(int i=0; i<m; i++){
        cin>>input>> first_person;

        party.push_back(first_person);

        while(--input){
            cin>>person;
            unionNum(first_person, person);
        }
    }

    int result = foolParty(m, party);

    cout<< result<<'\n';

    return 0;
}