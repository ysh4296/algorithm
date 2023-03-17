#include <algorithm>
#include <vector>

vector<int> arr;
vector<int> dp(n, 1);

int LIS() {
    int n = arr.size();
    int result = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}

vector<int> arr;
vector<int> dp(n, 0);
int LIS() {
    int n = arr.size();
    int length = 0;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.begin() + length, arr[i]);
        if (it == dp.begin() + length) {
            dp[length++] = arr[i];
        }
        else {
            *it = arr[i];
        }
    }

    return length;
}
