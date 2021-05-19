#include <iostream>

using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    LL dp[N+1];
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3 ; i <= N ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    if(N == 1){
        cout << 4;
    } else if(N == 2){
        cout << 6;
    } else if(N == 3){
        cout << 10;
    } else {
        cout << dp[N]*3 + dp[N-1]*2 + dp[N-2]*2 + dp[N-3];
    }
    return 0;
}
