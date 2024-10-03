#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long num){
    if(num<2) return false;
    for(long long i=2; i<=sqrt(num); i++){
        if(num%i==0) return false;
    }
    return true;
}

string convertK(int n, int k){
    string result="";
    while(n>0){
        result+=to_string(n%k); // 앞에 추가
        n=n/k;
    }
    reverse(result.begin(), result.end());
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    
    string kNum=convertK(n, k);
    
    int start=0;
    
    while(true){
        int idx=kNum.find('0', start); // 0의 위치 찾기
        
        if(idx==string::npos){ // 0이 더이상 없는 경우
            string s=kNum.substr(start);
            if(!s.empty()){
                long long num=stoll(s);
                if(isPrime(num)){
                    answer++;
                }
            }
            break;
        }
        
        string s=kNum.substr(start, idx-start);
        if(!s.empty()){
            long long num=stoll(s); // 십진수 변환
            if(isPrime(num)){
                answer++;
            }
        }
        
        start=idx+1;
    }
    
    return answer;
}