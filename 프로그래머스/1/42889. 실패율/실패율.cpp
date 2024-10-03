#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int total=stages.size();
    
    vector<int> players(N+2, 0);
    for(auto s:stages){
        players[s]++;
    }
    
    vector<pair<int, float>> failure;
    
    for(int i=1; i<=N; i++){
        if(total>0){
            float fail=(float)players[i]/(float)total;
            failure.push_back({i,fail});
            total-=players[i];
        }
        else{
            failure.push_back({i,0});
        }
    }
    
    sort(failure.begin(), failure.end(), compare);
    
    for(auto f:failure){
        answer.push_back(f.first);
    }
    
    return answer;
}