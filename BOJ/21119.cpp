#include <iostream>
#include <cmath>
#define MAX 262145
using namespace std;
typedef long long LL;
int N;
LL ans[MAX] = {0,};
LL c[19][2][2] = {0,}; // c [2^i][xi][yi]
int x[] = {0,0,1,1};
int y[] = {0,1,0,1};
LL A[MAX] = {0,};
LL B[MAX] = {0,};
LL power[18] = {0,};
LL cal(LL a,LL b){
    LL res = 0;
    for(int i = 0 ; i < N ; i++){
        res += c[i][(a&(1<<i)) == 0 ? 0 : 1][(b&(1<<i)) == 0 ? 0 : 1] * power[i];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    string str;
    int mv = pow(2,N);
    for(int i = 0 ; i < N ; i++){
        cin >> str;
        power[i] = pow(2,i);
        for(LL j = 0 ; j < 4 ; j++){
            c[i][x[j]][y[j]] = (int)(str[j] - '0');
        }
    }
    for(int i = 0 ; i < mv ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < mv ; i++){
        cin >> B[i];
        for(int j = 0 ; j < mv ; j++){
            if(B[i]*A[j] != 0){
                ans[cal(j,i)] += A[j]*B[i];
            }        
        }
    }
    for(int i = 0 ; i < mv ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
// 완전히 정신이 나가버린 문제(미해결)
// 이중for문을통해 A와B의 모든조합을 확인하여 새로운 배열 result를 생성해야함
// 곱연산을 합치는 과정이 필요하나 현재 지식으로는 해결이 불가
