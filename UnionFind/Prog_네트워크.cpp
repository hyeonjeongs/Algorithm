#include <string>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node) {
    if(parent[node] < 0) {
        return node;
    }

    return parent[node] = findParent(parent[node]);
}

void unionNetwork(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);

    if(parentA == parentB)
        return;
    if(parentA < parentB) {
        parent[parentA] += parent[parentB];
        parent[parentB] = parentA;
    } else{
        parent[parentB] += parent[parentA];
        parent[parentA] = parentB;
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    parent.assign(n,-1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(computers[i][j] && i!=j) {
                unionNetwork(i, j);
            }
        }
    }

    for(int num : parent) {
        if(num <0) {
            answer++;
        }
    }

    return answer;
}
\