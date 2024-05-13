#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> box;
    vector<bool> visited;
    visited.assign(cards.size()+1, false);

    for(int i=0; i<cards.size(); i++) {
        int cnt = 0;
        int current = cards[i];
        while(!visited[current]) {
            cnt++;
            visited[current] = true;
            current = cards[current];
        }
        if(cnt>0) {
            box.push_back(cnt);
        }
    }
    sort(box.begin(), box.end(), greater<>());
    if(box.size()>1) {
        return box[0] * box[1];
    }
    return 0;
}