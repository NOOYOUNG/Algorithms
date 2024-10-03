#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> status;
    vector<string> user;
    unordered_map<string, string> userNick;
    
    for(int i=0; i<record.size(); i++){
        int idx=record[i].find(' ');
        string state=record[i].substr(0, idx);
        status.push_back(state);
        
        string uid;
        if(state=="Leave"){
            uid=record[i].substr(idx+1);
        }
        else{
            int idx2=record[i].find(' ', idx+1);
            uid=record[i].substr(idx+1, idx2-idx-1);
            string nick=record[i].substr(idx2+1);
            userNick[uid]=nick;
        }
        user.push_back(uid);
    }
    
    for(int i=0; i<record.size(); i++){
        string result="";
        result+=userNick[user[i]];
        if(status[i]=="Enter"){
            result+="님이 들어왔습니다.";
        }
        else if(status[i]=="Leave"){
            result+="님이 나갔습니다.";
        }
        else if(status[i]=="Change"){
            continue;
        }
        answer.push_back(result);
    }
    
    return answer;
}