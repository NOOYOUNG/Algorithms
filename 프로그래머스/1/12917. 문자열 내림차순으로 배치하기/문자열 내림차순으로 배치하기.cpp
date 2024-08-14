#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<char> chars(s.begin(), s.end());
    
    sort(chars.rbegin(), chars.rend()); //reverse를 통한 역순 정렬
    
    string answer(chars.begin(), chars.end());
    
    return answer;
}