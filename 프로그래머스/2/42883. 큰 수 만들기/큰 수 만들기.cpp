#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> v;
    
    for(char n:number){
        // 현재 숫자가 벡터의 마지막 숫자보다 크고, k가 남아있는 동안
        while(!v.empty() && v.back()<n && k>0){
            v.pop_back(); // (맨뒤)가장 작은 숫자를 제거
            k--; // 제거한 숫자만큼 k 감소
        }
        v.push_back(n);
    }
    
    for(char ch:v){
        answer+=ch;
    }
    
    if(k>0){
        answer.erase(answer.end()-k, answer.end());
    }
    
    return answer;
}