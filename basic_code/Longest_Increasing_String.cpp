#include <algorithm>
#include <vector>

vector<int> arr;
vector<int> dp(n, 1);

int LIS() {// n^2의 시간복잡도를 가지는 알고리즘 dp[i] 배열에는 i번째 원소까지 배열 중 lis의 길이가 저장된다.
    int n = arr.size();
    int result = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1); // 현재값과 새로 발생하는 length중 큰값을 저장
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}

vector<int> arr;
vector<int> dp(n, 0);

int LIS() {// nlog(n)의 시간복잡도를 가지는 알고리즘 dp 배열은 각 위치에 대해 해당 인덱스 길이의 LIS의 마지막 원소 중 가능한 가장 작은 값을 유지한다.
    int n = arr.size();
    int length = 0;

    for (int i = 0; i < n; i++) {
        int index = lower_bound(dp.begin(), dp.begin() + length, arr[i]) - dp.begin(); // lowerbonud함수를 통한 index 찾기
        if (index == length) { // can add current index
            dp.push_back(arr[i]);
            length++;
        }
        else { // can optimize
            dp[index] = arr[i];
        }
    }

    return length;
}
