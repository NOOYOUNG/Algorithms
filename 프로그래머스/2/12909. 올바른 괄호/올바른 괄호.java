class Solution {
    boolean solution(String s) {
        int open_cnt = 0;  // 여는 괄호의 개수를 셀 변수
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            
            if (ch == '(') {
                open_cnt++;  // 여는 괄호의 경우 카운트 증가
            } else if (ch == ')') {
                open_cnt--;  // 닫는 괄호의 경우 카운트 감소
                
                // 닫는 괄호가 여는 괄호보다 많아지면 올바르지 않음
                if (open_cnt < 0) {
                    return false;
                }
            }
        }
        
        // 여는 괄호와 닫는 괄호의 개수가 같으면 true, 그렇지 않으면 false
        return open_cnt == 0;
    }
}