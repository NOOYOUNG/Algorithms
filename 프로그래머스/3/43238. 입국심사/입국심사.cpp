#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long min=1; // 최소 시간은 1분으로 설정
    long long max=n*(long long)times.back(); // 최대 시간은 가장 느린 심사관이 모든 사람을 처리하는 경우
    long long answer = max;
    
    // 이분 탐색 시작
    while(min<=max){
        long long mid=(min+max)/2;
        long long cnt=0; // mid시간 동안 처리할 수 있는 총 인원 수
        for(auto t:times){
            cnt+=(mid/t);
        }
        
        if(cnt>=n){ // 모든 사람이 심사를 받을 수 있는 경우
            answer=mid;
            max=mid-1; // right를 mid-1로 갱신하여 더 작은 범위 탐색
        }
        else{ // 처리할 수 있는 인원이 부족한 경우,
            min=mid+1; // left를 mid+1로 갱신하여 더 큰 범위 탐색
        }
    }
    
    return answer;
}