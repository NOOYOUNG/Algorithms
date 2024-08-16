#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0, andcnt=0;
    
    vector<string> s1;
    vector<string> s2;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i=0; i<str1.length()-1; i++){
        string a=str1.substr(i,2);
        if(isalpha(a[0]) && isalpha(a[1])){
            s1.push_back(a);    
        }
        
    }
    
    for(int i=0; i<str2.length()-1; i++){
        string a=str2.substr(i,2);
        if(isalpha(a[0]) && isalpha(a[1])){
            s2.push_back(a);    
        }
    }
    
    if(s1.empty()&&s2.empty()){
        return 65536;
    }
    
    int totalcnt=s1.size()+s2.size();
    
    if(s1.size()>s2.size()){
        for(int i=0; i<s2.size(); i++){
            auto iter=find(s1.begin(), s1.end(), s2[i]);
            if(iter!=s1.end()){ // 값을 찾으면 해당 값을 가리키는 iterator를 반환하고, 값을 찾지 못하면 s1.end()를 반환
                andcnt++;
                s1.erase(iter); // 교집합 s1에서 제거
            }
        }
    }
    else{
        for(int i=0; i<s1.size(); i++){
            auto iter=find(s2.begin(), s2.end(), s1[i]);
            if(iter!=s2.end()){
                andcnt++;
                s2.erase(iter);
            }
        }
    }
    
    totalcnt-=andcnt;
    
    if(totalcnt==0){
        return 65536;
    }
    
    double tmp=(double)andcnt/(double)totalcnt;
    answer=tmp*65536;
    
    return answer;
}