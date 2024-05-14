#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
map<string, int> person;
map<int, int> parent;
vector<int> result;

void makeParent(vector<string> referral) {

    for(int i=0; i<referral.size(); i++) {
        if(referral[i]=="-") {
            parent[i] = -1;
            continue;
        }
        int parent_index = person[referral[i]];
        parent[i]=parent_index;
    }

}

void dfs(int sells, int price) {

    while(1) {
        if(sells== -1 || price==0){
            return;
        }

        result[sells]+= price - price/10;

        price = price/10;
        sells = parent[sells];

    }

}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;


    result.assign(enroll.size(), 0);

    for(int i=0; i<enroll.size(); i++) {
        person.insert({enroll[i], i});
    }

    makeParent(referral);

    for(int i=0; i<seller.size(); i++) {
        int sells = person[seller[i]];
        int price = amount[i]*100;

        dfs(sells, price);
    }


    answer = result;
    return answer;
}