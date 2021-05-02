#include <iostream>
#include <cmath>
#define MAX 262145
using namespace std;
typedef long long LL;
int N;
LL ans[MAX] = {0,}; //각 조합의 원소 개수
LL c[19][2][2] = {0,}; // c [2^i][xi][yi]로 대응되는 집합
int x[] = {0,0,1,1};
int y[] = {0,1,0,1};
LL A[MAX] = {0,}; //집합 A
LL B[MAX] = {0,}; //집합 B
LL power[18] = {0,}; //거듭제곱을 저장한 배열 power[i] == pow(2,i)
LL cal(LL a,LL b){ // 입력된 A,B의 집합 index를 비트연산하여 ans속 집합 index번호를 찾아냄
    LL res = 0;
    for(int i = 0 ; i < N ; i++){
        res += c[i][(a&(1<<i)) == 0 ? 0 : 1][(b&(1<<i)) == 0 ? 0 : 1] * power[i];
    }
    return res; // res == A,B의 집합 index의 조합에 연결될 ans의 집합 index
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
        if(B[i] != 0){
            for(int j = 0 ; j < mv ; j++){
                if(A[j] != 0){
                    ans[cal(j,i)] += A[j]*B[i]; //A,B의 집합속 조합에 A[j]*B[i] != 0 이라면 조합에 대응한 ans[]의 index번호를 추적하여 결과입력
                }        
            }
        }
    } // 이 함수의 시간복잡도는 O((2^N)^N) 즉 최대 60억번의 계산이 필요한 구성이다.
    for(int i = 0 ; i < mv ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
// 완전히 정신이 나가버린 문제(미해결)
// 이중for문을통해 A와B의 모든조합을 확인하여 새로운 배열 result를 생성해야함
// 곱연산을 합치는 과정이 필요하나 현재 지식으로는 해결이 불가
