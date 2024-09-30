#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visited(51, false);

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if(find(words.begin(), words.end(), target)==words.end()){
        return answer;
    }
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty()){
        string start=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        for(int i=0; i<words.size(); i++){
            int diff=0;
            
            if(visited[i]) continue;
            
            for(int j=0; j<begin.size(); j++){
                if(start[j]!=words[i][j]){
                    diff++;
                }
            }
            
            if(diff==1){
                if(words[i]==target){
                    return cnt+1;
                }
                visited[i]=true;
                q.push({words[i], cnt+1});
            }
        }
    }
    
    return 0;
}