#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isUnique(vector<int> cols, vector<vector<string>> relation){
    set<string> uniq;
    for(auto r:relation){
        string key="";
        for(int col:cols){
            key+=r[col]+"|";
        }
        if(uniq.count(key)){
            return false;
        }
        uniq.insert(key);
    }
    return true;
}

bool isMinimal(vector<int> cols, vector<vector<int>> candidates){
    for(auto c:candidates){
        if(includes(cols.begin(), cols.end(), c.begin(), c.end())){
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rows=relation.size();
    int cols=relation[0].size();
    vector<vector<int>> candidates;
    
    for(int i=1; i<=cols; i++){ // 1개부터 최대 cols개까지의 컬럼 조합을 구함
        vector<bool> select(cols, false); // 선택할 컬럼의 여부
        fill(select.end()-i, select.end(), true); // 뒤에서 r개의 컬럼을 true로 설정
        
        do{
            // 현재 선택된 컬럼들의 인덱스를 구함
            vector<int> colSelected; // 선택된 컬럼의 인덱스를 저장
                for(int j=0; j<cols; j++){
                    if(select[j]){
                        colSelected.push_back(j);
                    }
                }
            
            // 유일성 체크: 선택된 컬럼들로 만들어진 조합이 모든 행에서 유일한지 검사
            if(isUnique(colSelected, relation)){
                // 최소성 체크: 현재 조합이 이미 존재하는 후보키들의 상위 집합인지 확인
                if(isMinimal(colSelected, candidates)){
                    candidates.push_back(colSelected);
                    answer++;
                }
            }
        } while (next_permutation(select.begin(), select.end())); // 다음 조합 생성
    }
    
    return answer;
}