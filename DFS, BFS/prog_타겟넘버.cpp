#include <string>
#include <vector>

using namespace std;

int result =0;
vector<bool> visited;
vector<int> nums;
void addNumber(int index, int target) {

    if(index >nums.size()) {
        return;
    }

    int num=0;
    for(int i=0;i <nums.size(); i++) {
        num += nums[i];
    }
    if(num == target) {
        result++;
    }

    for(int i = index; i<nums.size();i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        nums[i] = -nums[i];
        addNumber(i+1, target);
        visited[i] = false;
        nums[i] = -nums[i];
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    visited.assign(numbers.size(), 0);
    nums = numbers;

    for(int i=0; i<numbers.size(); i++) {
        nums[i] = -nums[i];
        addNumber(i+1,target);
        nums[i] = -nums[i];
    }

    answer = result;
    return answer;
}