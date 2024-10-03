#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    queue<int> q1, q2;
    long long s1=0, s2=0;
    
    for(auto q:queue1){
        s1+=q;
        q1.push(q);
    }
    for(auto q:queue2){
        s2+=q;
        q2.push(q);
    }
    
    if((s1+s2)%2!=0){
        return answer;
    }
    
    long long target=(s1+s2)/2;
    int len1=queue1.size();
    int len2=queue2.size();
    
    int move=0;
    while(move<=(len1+len2)*2){  // 무한 루프 방지를 위한 이동 횟수 제한
        if(s1==target){
            return move;
        }
        
        if(s1<target){
            int n=q2.front();
            q2.pop();
            s2-=n;
            s1+=n;
            q1.push(n);
        }
        else{
            int n=q1.front();
            q1.pop();
            s1-=n;
            s2+=n;
            q2.push(n);
        }
        move++;
    }
    
    return answer;
}