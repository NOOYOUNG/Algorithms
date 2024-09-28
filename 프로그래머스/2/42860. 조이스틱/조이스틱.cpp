#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
     int answer = 0;
    int len = name.length();
    
    for (int i = 0; i < len; i++) {
        char ch = name[i];
        answer += min(ch - 'A', 'Z' - ch + 1);
    }
    
    int min_move=len-1; // 기본적으로 오른쪽으로만 이동하는 거리
    for(int i=0; i<len; i++){
        int next=i+1; // A가 끝나는 위치
        while(next<len && name[next]=='A'){
            next++;
        }
        int left=i; // 왼쪽으로 이동해야 하는 거리
        int right=len-next; // 오른쪽으로 이동해야 하는 거리
        min_move=min(min_move, i+(len-next)+min(left, right));
    }
    answer+=min_move;

    return answer;
}