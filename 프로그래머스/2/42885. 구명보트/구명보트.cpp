#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int currentWeight=0;
    sort(people.begin(), people.end());
    
    for(int i=0, j=people.size()-1; i<=j;){
        if(people[i]+people[j]<=limit){
            i++;
        }
        
        j--;
        answer++;
    }
    
    return answer;
}