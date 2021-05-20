#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string sum(string a , string b){
    string result = "";
    int len = abs((int)a.length() - (int)b.length());
    string st = "";
    for(int i = 0 ; i < len ; i++){
        st += "0";
    }
    while(a.length() < b.length()) a = st + a;
    while(a.length() > b.length()) b = st + b;
    int carry = 0;
    int num;
    for(int i = a.length()-1 ; i >=0 ; i--){
        num = (a[i] - '0' + b[i] - '0' + carry)%10;
        result += to_string(num);
        carry = (a[i] - '0' + b[i] - '0' + carry)/10;
    }
    if(carry) result += '1';
    reverse(result.begin(),result.end());
    return result;
}
// reverse 를 활용한 자체복사구조의 제거
// result = tostring() + result;에서 result+= a 로
// 속도향상
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string dp[10001];
    cin >> n;
    dp[0] = '0';
    dp[1] = '1';
    for(int i = 2 ; i <= n ; i++){
        dp[i] = sum(dp[i-1],dp[i-2]);
    }
    cout << dp[n];
    return 0;
}
