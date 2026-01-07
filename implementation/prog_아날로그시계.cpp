#include <string>
#include <vector>
#include <cmath>

using namespace std;
double s = 6.0;
double m = 0.1;
double h = 1.0/120.0;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int start= s1 + m1*60 + h1*60*60;
    int end = s2 + m2*60 + h2*60*60;
    if(start ==0 || start == 12*3600) {
        answer++;
    }

    for(int i=start; i<end; i++) { // 초당 움직임
        double h_cur = fmod(i / 120.0, 360.0);
        double m_cur = fmod(i / 10.0, 360.0);
        double s_cur = fmod(i * 6.0, 360.0);

        double h_nexts = fmod((i+1)/120.0, 360.0);
        if(h_nexts == 0.0){
            h_nexts = 360.0;
        }
        double m_nexts = fmod((i+1)/10.0, 360.0);
        if(m_nexts == 0.0){
            m_nexts = 360.0;
        }
        double s_nexts = fmod((i+1)*6.0, 360.0);
        if(s_nexts == 0.0){
            s_nexts = 360.0;
        }
        if(s_cur< h_cur && s_nexts>=h_nexts) {
            answer++;
        }
        if(s_cur< m_cur && s_nexts>=m_nexts) {
            answer++;
        }
        if(s_nexts==h_nexts && h_nexts == m_nexts) {
            answer--;
        }

    }

    return answer;
}