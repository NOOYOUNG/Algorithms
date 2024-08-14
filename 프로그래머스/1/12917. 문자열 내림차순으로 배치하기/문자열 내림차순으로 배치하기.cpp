#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<char> chars(s.begin(), s.end());
    
    sort(chars.rbegin(), chars.rend());
    
    string answer(chars.begin(), chars.end());
    
    return answer;
}