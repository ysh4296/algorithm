#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    cin >> test_case;
    int coin[21] = {0,};
    int N;
    int M;
    for(int i = 0 ; i < test_case ; i++){
        cin >> N;
        memset(coin,0,sizeof(coin));
        for(int a = 1 ; a <= N ; a++){
            cin >> coin[a];
        }
        cin >> M;
        int dp[10001] = {0,};
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int a = 1 ; a <= N ; a++){
            for(int b = coin[a] ; b <= M ; b++){
                dp[b] += dp[b - coin[a]];
            }
        }
        cout << dp[M] << endl;
    }
    return 0;
}
// 가장 기본적인 형태의 냅색 문제로 1개씩 동전의 종류를 추가해주는 기본 알고리즘 형태이다.
