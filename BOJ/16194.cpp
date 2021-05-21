#include <iostream>
#include <cstring>
using namespace std;
#define INF 1e9
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int cost[N+1] = {0,};
    for(int i = 1 ; i <= N ; i++){
        cin >> cost[i];
    }
    int dp[N+1];
    for(int i = 1 ; i <= N ; i++) dp[i] = INF;
    dp[0] = 0;
    for(int i = 0 ; i <= N ; i++){
        for(int p = i ; p <= N ; p++){
            dp[p] = min(dp[p],dp[p-i] + cost[i]);
        }
    }
    cout << dp[N];
    
    
    return 0;
}
// napsack 문제
