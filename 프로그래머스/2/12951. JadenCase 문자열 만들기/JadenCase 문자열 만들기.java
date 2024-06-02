import java.util.StringTokenizer;
class Solution {
    public String solution(String s) {
        // 문자열을 모두 소문자로 변환
        s = s.toLowerCase();

        // StringTokenizer를 사용하여 문자열을 공백 기준으로 토큰으로 나눔
        StringTokenizer st = new StringTokenizer(s, " ", true);

        // 변환된 문자열을 저장할 StringBuilder
        StringBuilder sb = new StringBuilder();

        // 토큰이 남아있는 동안 반복
        while (st.hasMoreTokens()) {
            // 현재 토큰 가져오기
            String str = st.nextToken();

            // 공백인 경우 그대로 추가
            if (str.equals(" ")) {
                sb.append(str);
            } else {
                // 첫 글자를 대문자로 변환
                String first = str.substring(0, 1).toUpperCase();
                // 나머지 글자는 그대로 유지
                String others = str.substring(1);

                // 변환된 첫 글자와 나머지 글자를 추가
                sb.append(first);
                sb.append(others);
            }
        }

        return sb.toString();
    }
}