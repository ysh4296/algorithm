#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dp[41] = {1,1,2,};
    int n,m;
    cin >> n;
    cin >> m;
    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    int tmp = 0 ,ans = 1; 
    for(int i=0;i<m;i++) { 
        int k;
        cin >> k;
        ans *= dp[k-tmp-1]; 
        tmp = k; 
    }
    ans *= dp[n - tmp];
    cout << ans;
    return 0;
}
