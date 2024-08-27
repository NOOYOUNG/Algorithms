#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_map<int, int> ponkemon;
    
    for(auto it: nums){
        ponkemon[it]++;
    }
    
    int N=nums.size();
    
    if(ponkemon.size()>=N/2){
        answer=N/2;
    }
    else{
        answer=ponkemon.size();
    }
    
    return answer;
}