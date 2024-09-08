#include <iostream>
using namespace std;

int dp[301];
int arr[301] = {0, };

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
	
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1], arr[2])+arr[3];
    
    for(int i = 4; i <= N; i++){
        int a=dp[i-2]+arr[i];
        int b=dp[i-3]+arr[i-1]+arr[i];
        dp[i]=max(a,b);
    }
    
    cout << dp[N] << endl;
}