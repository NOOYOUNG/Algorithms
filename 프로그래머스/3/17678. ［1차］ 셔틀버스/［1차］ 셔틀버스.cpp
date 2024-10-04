#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> people;
    for(auto t:timetable){
        int hour=stoi(t.substr(0,2));
        int min=stoi(t.substr(3,2));
        int time=hour*60+min;
        people.push_back(time);
    }
    
    sort(people.begin(), people.end());
    
    int start=540;
    vector<int> shuttles;
    for(int i=0; i<n; i++){
        int time=start+(i*t);
        shuttles.push_back(time);
    }
    
    int idx=0;
    for(auto shuttle:shuttles){
        int cnt=0;
        
        while(idx<people.size() && people[idx]<=shuttle && cnt<m){
            cnt++;
            idx++;
        }
        
        if(shuttle==shuttles.back()){
            if(cnt<m){
                string h="", m="";
                int time=shuttle;
                int hour=time/60;
                if(hour<10){
                    h="0"+to_string(hour);
                }
                else{
                    h=to_string(hour);
                }
                
                int min=time%60;
                if(min<10){
                    m="0"+to_string(min);
                }
                else{
                    m=to_string(min);
                }
                answer=h+":"+m;
            }
            else{
                string h="", m="";
                int time=people[idx-1]-1;
                int hour=time/60;
                if(hour<10){
                    h="0"+to_string(hour);
                }
                else{
                    h=to_string(hour);
                }
                
                int min=time%60;
                if(min<10){
                    m="0"+to_string(min);
                }
                else{
                    m=to_string(min);
                }
                
                answer=h+":"+m;
            }
        }
    }    
    
    return answer;
}