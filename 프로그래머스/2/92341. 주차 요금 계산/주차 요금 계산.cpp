#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int calMin(string time){
    int hour=stoi(time.substr(0,2));
    int min=stoi(time.substr(3,2));
    return hour*60+min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> inTime;
    map<string, int> parkTime;
    
    for(auto r:records){
        string time=r.substr(0, 5);
        string carNum=r.substr(6, 4);
        string status=r.substr(11, 3);
        
        int mins=calMin(time);
        
        if(status=="IN"){
            inTime[carNum]=mins;
        }
        else{
            parkTime[carNum]+=mins-inTime[carNum];
            inTime.erase(carNum);
        }
    }
    
    // 출차 기록 없는 차들 처리 (23:59 출차 처리)
    for(auto i:inTime){
        parkTime[i.first]+=calMin("23:59")-i.second;
    }
    
    for(auto p:parkTime){
        int totalTime=p.second;
        int totalPrice=fees[1];
        
        if(totalTime>fees[0]){
            totalPrice+=ceil((totalTime-fees[0])/(double)fees[2])*fees[3];
        }
        answer.push_back(totalPrice);
    }
    
    return answer;
}