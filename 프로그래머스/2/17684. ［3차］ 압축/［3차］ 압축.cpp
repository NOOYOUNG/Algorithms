#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;
    
    for(int i=1; i<=26; i++){
        string s(1, 'A'+(i-1)); // A~Z까지 길이가 1인 문자열 생성
        dic[s]=i;        
    }
    
    int idx=27;
    string w="";
    
    for(int i=0; i<msg.length(); i++){
        w+=msg[i];
        
        if(dic.find(w)==dic.end()){ // w가 사전에 없다면
            dic[w]=idx++; // 새로운 단어 추가
            w.pop_back(); // 마지막 문자 제거
            answer.push_back(dic[w]); // 사전에서 찾은 단어의 색인 추가
            w=msg[i]; // 현재 문자로 단어 초기화
        }
    }
    
    if(!w.empty()){
        answer.push_back(dic[w]);
    }
    
    return answer;
}