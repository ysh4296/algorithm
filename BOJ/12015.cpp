#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr;
    arr.push_back(-1e9);
    int result = 0,temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;
        if(temp > arr.back()){
            arr.push_back(temp);
            result++;
        } else {
            vector<int>::iterator pi = lower_bound(arr.begin(),arr.end(),temp);
            *pi = temp;
        }
    }
    cout << result;
    return 0;
}
// 오랜만에 다시풀어본 재채점문제..
// 역시 가장먼저 떠오른 풀이는 DP 풀이로 문제의 N크기를 고려하지 않았다.
// 이분탐색을 통한 정렬로 최고의 상황에서 그보다 좋은수가 왔을때 카운트를 늘려 최장수열을 구한다.
