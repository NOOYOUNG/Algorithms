#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;  // 입력된 문자열을 str에 저장, 예시에서는 "3(2(ab)cd)"
    
    stack<string> s;  // 문자열의 길이와 괄호를 저장할 스택 생성
    
    for (int i = 0; i < str.size(); i++) {  // 문자열의 각 문자를 순회
        if (str[i] == ')') {  // 닫는 괄호 ')'를 만나면
            int sum = 0;  // 괄호 안의 문자열 길이를 저장할 변수
            while (true) {  // 여는 괄호 '('를 만날 때까지 스택에서 값을 꺼내며 반복
                string temp = s.top();  // 스택의 최상단 값을 가져옴
                if (temp.compare("(") == 0) {  // 여는 괄호 '('를 만나면
                    s.pop();  // 스택에서 '('를 제거
                    break;  // 반복문 종료
                }
                sum += stoi(temp);  // 스택에서 가져온 값을 정수로 변환하여 sum에 더함
                s.pop();  // 스택에서 현재 값을 제거
            }
            int num = stoi(s.top());  // 여는 괄호 앞에 있던 숫자(반복 횟수) 가져옴
            s.pop();  // 스택에서 이 숫자를 제거
            s.push(to_string(num * sum));  // 반복 횟수와 괄호 안 문자열 길이의 곱을 스택에 저장
        } else if (str[i] == '(') {  // 여는 괄호 '('를 만나면
            s.push("(");  // 스택에 '('를 저장
        } else if (i < str.size() - 1 && str[i + 1] == '(') {  
            // 현재 문자가 숫자이고 다음 문자가 '('일 경우 (반복 횟수를 나타냄)
            string a = "";  
            a = str[i];  // 현재 문자를 a에 저장 (숫자)
            s.push(a);  // 이 숫자를 스택에 저장
        } else {  
            // 그냥 문자일 경우
            string a = "";  
            a = str[i];  // 현재 문자를 a에 저장
            s.push(to_string(a.size()));  // 해당 문자의 길이(1)를 스택에 저장
        }
    }
    
    // 최종 길이를 계산하는 부분
    int ans = 0;  // 최종 길이를 저장할 변수
    if (s.size() > 1) {  // 스택에 여러 요소가 있을 경우
        while (!s.empty()) {  // 스택이 비어있지 않을 때까지 반복
            ans += stoi(s.top());  // 스택의 최상단 값을 ans에 더함
            s.pop();  // 스택에서 값을 제거
        }
    } else {  // 스택에 하나의 요소만 있을 경우
        ans = stoi(s.top());  // 그 값을 ans로 설정
    }
    
    cout << ans;  // 최종 길이를 출력
    return 0;  // 프로그램 종료
}