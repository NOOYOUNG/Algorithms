#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd=__gcd(n, m);
    answer.push_back(gcd);
    
    int min=n*m/gcd;
    answer.push_back(min);    
    
    return answer;
}