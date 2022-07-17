/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll Answer;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		ll N, K;
		cin >> N >> K;
		vector<ll> dp(N + 1, 0);
		for (int i = 0; i < N; i++) {
			ll value;
			cin >> value;
			dp[i + 1] = dp[i] + value;
		}
		ll divider = (dp[N] / K);
		vector<ll> caseMult(K + 1, 0);
		if (dp[N] % K != 0) {
			caseMult[K - 1] = 0;
		} else if (divider != 0) {
			caseMult[0] = 1;
			for (ll i = 1; i < N; i++) {
				ll cutPosition = dp[i] / divider;
				if (dp[i] % divider == 0 && cutPosition > 0 && cutPosition < K) {
					caseMult[cutPosition] += caseMult[cutPosition - 1];
					caseMult[cutPosition] %= 1000000007;
				}
			}
		} else {
			ll combN = -1, combR = K-1, nCr = 0;
			for (ll i = 1; i < N; i++) {
				if (dp[i] == 0) {
					// add point
					combN++;
					if (combN == combR-1) {
						nCr = 1;
					}
					else if (combN > combR-1) {
						nCr = nCr + (nCr * combR / (combN - combR+1));
						nCr %= 1000000007;
					}
				}
			}
			caseMult[K - 1] = nCr;
		}
		caseMult[K] = caseMult[K - 1];
		cout << "Case #" << test_case + 1 << endl;
		cout << caseMult[K] << endl;
		caseMult.clear();
	}
	return 0;//Your program should return 0 on normal termination.
}
