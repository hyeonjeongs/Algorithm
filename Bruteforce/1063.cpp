#include <iostream>
#include <vector>

using namespace std;

void moveLocation(vector<int>& kings, vector<int>& stones, string input) {
    int x,y;
    if(input=="L"){
        x = kings[0] - 1;
        if(x<=0 || x>=9) {
            return;
        }
        if(stones[0]==x && stones[1]==kings[1]){
            if(stones[0]-1<=0 || stones[0]-1>=9){
                return;
            }
            stones[0] = x-1;
        }
        kings[0]=x;
    }
    if(input =="R") {
        x = kings[0] + 1;
        if(x<=0 || x>=9) {
            return;
        }
        if(stones[0]==x && stones[1]==kings[1]){
            if(stones[0]+1<=0 || stones[0]+1>=9){
                return;
            }
            stones[0] = x+1;
        }
        kings[0]=x;
    }
    if(input =="B") {

        y = kings[1] - 1;
        if(y<=0 || y>=9) {
            return;
        }
        if(stones[1]==y && stones[0]==kings[0]){
            if(stones[1]-1<=0 || stones[1]-1>=9){
                return;
            }
            stones[1] = y-1;
        }
        kings[1]=y;
    }
    if(input =="T") {
        y = kings[1] + 1;

        if(y<=0 || y>=9) {
            return;
        }
        if(stones[1]==y && stones[0]==kings[0]){
            if(stones[1]+1<=0 || stones[1]+1>=9){
                return;
            }
            stones[1] = y+1;
        }
        kings[1]=y;
    }
    if(input =="RT") {
        y = kings[1] + 1;
        x = kings[0] + 1;

        if(x<=0 || x>=9 || y<=0 || y>=9) {
            return;
        }
        if(stones[1]==y && stones[0]==x){
            if(stones[1]+1<=0 || stones[1]+1>=9 || stones[0]+1<=0 || stones[0]+1>=9){
                return;
            }
            stones[1] = y+1;
            stones[0] = x+1;
        }
        kings[1]=y;
        kings[0]=x;
    }
    if(input =="LT") {
        y = kings[1] + 1;
        x = kings[0] - 1;
        if(x<=0 || x>=9 || y<=0 || y>=9) {
            return;
        }
        if(stones[1]==y && stones[0]==x){
            if(stones[1]+1<=0 || stones[1]+1>=9 || stones[0]-1<=0 || stones[0]-1>=9){
                return;
            }
            stones[1] = y+1;
            stones[0] = x-1;
        }
        kings[1]=y;
        kings[0]=x;
    }
    if(input =="RB") {
        y = kings[1] - 1;
        x = kings[0] + 1;
        if(x<=0 || x>=9 || y<=0 || y>=9) {
            return;
        }
        if(stones[1]==y && stones[0]==x){
            if(stones[1]-1<=0 || stones[1]-1>=9 || stones[0]+1<=0 || stones[0]+1>=9){
                return;
            }
            stones[1] = y-1;
            stones[0] = x+1;
        }
        kings[1]=y;
        kings[0]=x;
    }
    if(input =="LB") {
        y = kings[1] - 1;
        x = kings[0] - 1;
        if(x<=0 || x>=9 || y<=0 || y>=9) {
            return;
        }
        if(stones[1]==y && stones[0]==x){
            if(stones[1]-1<=0 || stones[1]-1>=9 || stones[0]-1<=0 || stones[0]-1>=9){
                return;
            }
            stones[1] = y-1;
            stones[0] = x-1;
        }
        kings[1]=y;
        kings[0]=x;
    }
}

int main() {
    string king, stone;
    vector<int> kings(2,0);
    vector<int> stones(2,0);

    int n;
    cin>>king>>stone>>n;

    kings[0] = int(king[0]) - 64;
    kings[1] = king[1] - '0';
    stones[0] = int(stone[0]) - 64;
    stones[1] = stone[1] - '0';


    for(int i=0; i<n; i++) {
        string input;
        cin>>input;
        moveLocation(kings, stones, input);
    }
    cout<< char(kings[0]+64)<<char(kings[1]+48)<< '\n';
    cout<< char(stones[0]+64)<<char(stones[1]+48)<< '\n';


    return 0;
}