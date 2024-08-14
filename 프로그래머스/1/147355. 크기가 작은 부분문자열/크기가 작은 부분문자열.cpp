#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int plen=p.length();
    int tlen=t.length();
    
    if(plen==1){
        for(int i=0; i<tlen; i++){
        string tmp=t.substr(i,1);
        long tInt=stol(tmp), pInt=stol(p);
        
        if(tInt<=pInt) answer++;
        }
    }
    
    else{
        for(int i=0; i<=tlen-plen; i++){
            string tmp=t.substr(i,plen);
            long tInt=stol(tmp), pInt=stol(p);

            if(tInt<=pInt) answer++;
        }
        
    }
    
    return answer;
}