using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    long long result=0;
    for(int i=1; i<=count; i++){
        result+=static_cast<long long>(price)*i;
    }
    
    answer=result-(static_cast<long long>(money));
    
    if(answer<0){
        answer=0;
    }
    
    
    return answer;
}