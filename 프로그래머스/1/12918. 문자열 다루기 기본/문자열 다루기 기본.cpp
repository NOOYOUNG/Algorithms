#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size()==4 || s.size()==6){
        for(int i=0; i<s.length(); i++){
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
                answer=false;
            }
        }
    }
    else{
        answer=false;
    }
    
    return answer;
}