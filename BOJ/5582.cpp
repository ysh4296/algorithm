#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str1,str2;
    cin >> str1 >> str2;
    int dp[str1.length()+1][str2.length()+1];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    int answer = 0;
    for(int i = 1 ; i <= (int)str1.length() ; i++){
        for(int j = 1 ; j <= (int)str2.length() ; j++){
            if(str1.at(i-1) == str2.at(j-1)){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
            answer = max(answer,dp[i][j]);
        }
    }
    cout << answer;
    return 0;
}
