#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string id="";
    for(int i=0; i<new_id.size(); i++){
        char c=tolower(new_id[i]);
        if(isalnum(c) || c=='-' || c=='_' || c=='.'){
            id+=c;
        }
    }
    
    for(int i=0; i<id.size(); i++){
        if(!(id[i]=='.' && (i>0 && id[i-1]=='.'))){
            answer+=id[i];
        }
    }

    if(!answer.empty() && answer.front()=='.'){
        answer.erase(answer.begin());
    }
    if(!answer.empty() && answer.back()=='.'){
        answer.pop_back();
    }
    
    if(answer.empty()){
        answer="a";
    }
    
    if(answer.length()>15){
        answer=answer.substr(0,15);
        if(answer.back()=='.'){
            answer.pop_back();
        }
    }
    
    while(answer.length()<3){
        answer+=answer.back();
    }
    
    return answer;
}