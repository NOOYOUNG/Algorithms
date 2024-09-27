#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compareGenres(const pair<string, int>& a, const pair<string, int>& b){
    return a.second>b.second;
}

bool compareSongs(const pair<int, int>&a , const pair<int, int>& b){
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, vector<pair<int, int>>> playList;
    unordered_map<string, int> countList;
    
    for(int i=0; i<genres.size(); i++){
        countList[genres[i]]+=plays[i];
        playList[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    vector<pair<string, int>> sortedCount(countList.begin(), countList.end());
    sort(sortedCount.begin(), sortedCount.end(), compareGenres);
    
    for(auto genre:sortedCount){
        string genreName=genre.first;
        
        sort(playList[genreName].begin(), playList[genreName].end(), compareSongs);
        
        for(int i=0; i<min(2, (int)playList[genreName].size()); i++){
            answer.push_back(playList[genreName][i].first);
        }
    }
    
    return answer;
}