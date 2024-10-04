#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string u){
    stack<char> st;
    
    for(char c:u){
        if(c=='('){
            st.push(c);
        }
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty(); 
}

string solution(string p) {
    string answer = "";
    if(p.empty()){
        return answer;
    }
    
    int cnt=0;
    int idx=0;
    for(int i=0; i<p.length(); i++){
        if(p[i]=='('){
            cnt++;
        }
        else if(p[i]==')'){
            cnt--;
        }
        
        if(cnt==0){
            idx=i;
            break;
        }
    }
    
    string u=p.substr(0, idx+1);
    string v=p.substr(idx+1);
    
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    if(isValid(u)){
        v=solution(v);
        // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        answer=u+v;
    }
    else{
        // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
        // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        // 4-3. ')'를 다시 붙입니다.
        answer='('+solution(v)+')';

        // 4-4. u의 첫 번째와 마지막 문자를 제거하고,
        u.erase(0,1);
        u.erase(u.length()-1,1);
    
        // 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        for(int i=0; i<u.length(); i++){
            if(u[i]=='('){
                answer=answer+')';
            }
            else if(u[i]==')'){
                answer=answer+'(';
            }
        }   
    }
    
    return answer;
}