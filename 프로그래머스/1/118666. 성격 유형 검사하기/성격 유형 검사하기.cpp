#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int n=survey.size();
    unordered_map<string, int> scores={{"R", 0}, {"T", 0}, {"C", 0}, {"F", 0}, {"J", 0}, {"M", 0}, {"A", 0}, {"N", 0}};
    
    for(int i=0; i<n; i++){
        string s1=string(1,survey[i][0]);
        string s2=string(1,survey[i][1]);
        if(choices[i]<4){
            scores[s1]+=(4-choices[i]);
        }
        else if(choices[i]>4){
            scores[s2]+=(choices[i]-4);
        }
    }
    
    if(scores["R"]>scores["T"]){
        answer+="R";
    }
    else if(scores["R"]<scores["T"]){
        answer+="T";
    }
    else if(scores["R"]==scores["T"]){
        answer+="R";
    }

    if(scores["C"]>scores["F"]){
        answer+="C";
    }
    else if(scores["C"]<scores["F"]){
        answer+="F";
    }
    else if(scores["C"]==scores["F"]){
        answer+="C";
    }

    if(scores["J"]>scores["M"]){
        answer+="J";
    }
    else if(scores["J"]<scores["M"]){
        answer+="M";
    }
    else if(scores["J"]==scores["M"]){
        answer+="J";
    }

    if(scores["A"]>scores["N"]){
        answer+="A";
    }
    else if(scores["A"]<scores["N"]){
        answer+="N";
    }
    else if(scores["A"]==scores["N"]){
        answer+="A";
    }
    
    
    return answer;
}