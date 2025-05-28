#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, string> pi;
vector<pi> idxs; // count, string
map<string, int> maps; // string,index;
vector<int> result; // index가 course에서 받은 수 (2글자 일때 count 최대)

void findOrder(string order, int index, string str, vector<int> course) {

    for(int i=0; i<course.size(); i++) {
        if(course[i] == str.length()) {
            sort(str.begin(), str.end()); // 여기서 정렬하면됨
            if(maps.find(str)!= maps.end()) {
                idxs[maps[str]].first++;
            } else {
                maps[str] = idxs.size();
                idxs.push_back({1, str});
            }

            if(idxs[maps[str]].first>result[course[i]]) {
                result[course[i]] = idxs[maps[str]].first;
            }
        } else if(course[i] >str.length()) {
            break;
        }
    }

    for(int i=index; i<order.length(); i++) {

        findOrder(order, i+1, str+order[i], course);
    }

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    result.assign(course[course.size()-1]+1,0);

    for(int i=0; i<orders.size(); i++) {
        findOrder(orders[i], 0, "",course);
    }

    for(int i=0; i<idxs.size(); i++) {
        if(idxs[i].first >=2 && idxs[i].first == result[idxs[i].second.length()]) {
            answer.push_back(idxs[i].second);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}