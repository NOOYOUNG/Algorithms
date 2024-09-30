#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    vector<int> dist;
    
    dist.push_back(rocks[0]);
    for(int i=0; i<rocks.size()-1; i++){
        dist.push_back(rocks[i+1]-rocks[i]);
    }
    
    dist.push_back(distance-rocks.back());
    
    int min=1;
    int max=distance;
    
    while(min<=max){
        int mid=(min+max)/2;
        int removeCnt=0;
        int prev=0;
        
        for(int i=0; i<dist.size(); i++){
            if(dist[i]+prev<mid){
                removeCnt++;
                prev+=dist[i];
            }
            else{
                prev=0;
            }
        }
        if(removeCnt>n){
            max=mid-1;
        }
        else{
            answer=mid;
            min=mid+1;
        }
    }
    
    return answer;
}