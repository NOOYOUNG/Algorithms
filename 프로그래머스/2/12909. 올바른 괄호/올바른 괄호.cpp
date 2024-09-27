#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int check=0;
    
    for(char ch:s){
        if(ch=='('){
            check++;
        }
        else{
            check--;
            if(check<0) {
                answer=false;
                break;
            }
        }
    }
    
    if(check!=0) answer=false;
    
    return answer;
}