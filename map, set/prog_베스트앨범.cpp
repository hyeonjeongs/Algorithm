#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/*
 * classic, index -> map
 * vector<vector<int>> -> 고유번호 담은거
 *
 */

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
bool compare(pair<int, int> a, pair<int,int> b) {
    return a.second>b.second;
}

// classic, 개수, 인덱스
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int,int>> result_number(101, make_pair(0,0));
    int index =0;

    vector<vector<pair<int,int>>> genres_plays;
    map<string, int> maps; // genres, 고유번호 리스트 담은 index

    for(int i=0; i<genres.size(); i++) {
        if(maps.find(genres[i]) != maps.end()) {
            genres_plays[maps[genres[i]]].push_back(make_pair(i, plays[i]));
            result_number[maps[genres[i]]].second += plays[i];
            continue;
        }
        maps[genres[i]] = index++; // problem : 여기서 genres_plays 사이즈로 해서 문제 있을듯 (아에없는 경우도 있으니까)
        genres_plays.push_back({make_pair(i,plays[i])});
        result_number[maps[genres[i]]].first = maps[genres[i]];
        result_number[maps[genres[i]]].second += plays[i];
    }

    for(int i=0; i<index; i++) {
        sort(genres_plays[i].begin(), genres_plays[i].end(), cmp);
    }

    sort(result_number.begin(), result_number.end(), compare);

    for(int i=0; i<index; i++) {
        if(genres_plays[result_number[i].first].size()<2) {
            answer.push_back(genres_plays[result_number[i].first][0].second);
            continue;
        }
        answer.push_back(genres_plays[result_number[i].first][0].first);
        answer.push_back(genres_plays[result_number[i].first][1].first);
    }
    cout<< result_number[0].first << ", " << result_number[0].second << ", "<<result_number[1].first << ", " << result_number[1].second<<endl;

    return answer;
}
