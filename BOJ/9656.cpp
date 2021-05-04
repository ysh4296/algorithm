#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
	int dp[1001];
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	for (int i = 4; i <= n; ++i) {
		if (min(dp[i - 1], dp[i - 3]) == 1) {
			dp[i] = 0;
		}
		else {
			dp[i] = 1;
		}
	}
	if (dp[n] == 1) {
		cout << "SK" << endl;
	}
	else {
		cout << "CY" << endl;
	}
	return 0;
}
