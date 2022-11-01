#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tu;
int in_cnt =0;
bool cmp(const tu &a, const tu &b ){
    if(get<1> (a) == get<1> (b)) // 추천횟수 같은 경우 들어간 순서로 결정
        return get<2> (a) < get<2> (b);
    return get<1> (a) > get<1> (b); //추천 횟수 오름차순
}

void recommendStudent(vector<tu>& students,int n, int rec_number, vector<int> &picture){
    if(picture.size() <n){ //사진틀 안찬경우
        students.push_back(make_tuple(rec_number,1, ++in_cnt)); // 학생 번호, 추천 받은 횟수, 들어간 순서
        picture.push_back(rec_number);
        return;
    }

    auto it = find(picture.begin(), picture.end(), rec_number); //추천 번호 있는지 확인

    if(it == picture.end()){ //해당 숫자 없는 경우
        sort(students.begin(), students.end(), cmp);
        get<1> (students[0]) = 0; // 삭제된 경우 추천횟수 0으로 변경

        auto change_index = find(picture.begin(), picture.end(), get<0> (students[0]));
        picture[change_index-picture.begin()] = rec_number; //가장 오래된 사진 삭제 후 그 자리에 새로운거 저장

        int i;
        for(i=0; i<students.size(); i++){
            if(get<0> (students[i]) == rec_number)
                break;
        }
        if(i == students.size()) // 원래 나왔던 수이면 추가안해주고, 처음 나온 수면 추가해주기
            students.push_back(make_tuple(rec_number,1, ++in_cnt));

        return;
    }
    else{ //이미 사진틀에 저장된 경우
        for(int i=0; i< students.size(); i++){
            if(get<0> (students[i]) == rec_number){
                get<1> (students[i])++; //추천횟수 증가
                return;
            }
        }
    }

}

int main(){
    int n, s;// 사진틀의 개수, 총 추천 횟수
    cin>> n>>s;
    vector<tu> students;
    vector<int> picture;

    for(int i=0; i<s; i++){
        int rec_number;
        cin>>rec_number; // 추천하는 번호
        recommendStudent(students, n, rec_number, picture);
    }

    for(auto it: picture){
        cout<<it<<' ';
    }

    return 0;
}