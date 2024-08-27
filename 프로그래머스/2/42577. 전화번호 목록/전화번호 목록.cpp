#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end()); // 오름차순 정렬
    //전화번호 목록: ["123", "1235", "1236", "567", "890"]
    //정렬 후: ["123", "1235", "1236", "567", "890"]
    
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i]==phone_book[i+1].substr(0, phone_book[i].size())){ //다음 번호의 문자열 0에서부터 포함하고 있는지
            answer=false;
        }
    }
    
    return answer;
}