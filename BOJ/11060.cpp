#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int dp[N+1] = {0,};
    dp[1] = 1;
    for(int i = 1 ; i <= N ; i++){
        int num;
        cin >> num;
        if(dp[i] == 0) break;
        for(int j = 1 ; j <= num ; j++){
            if(i+j > N) break;
            if(dp[i+j] > dp[i] + 1 || dp[i+j] == 0) dp[i+j] = dp[i] + 1;
        }
    }
    if(dp[N] == 0) cout << -1;
    else cout << dp[N]-1;
    return 0;
}
