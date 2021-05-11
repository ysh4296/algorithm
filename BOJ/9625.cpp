#include <iostream>
#define MAX 50
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int A_cnt[MAX] = {0,};
    int B_cnt[MAX] = {0,};
    A_cnt[0] = 1;
    B_cnt[0] = 0;
    A_cnt[1] = 0;
    B_cnt[1] = 1;
    for(int i = 2 ; i <= N ; i++){
        A_cnt[i] = B_cnt[i-1];
        B_cnt[i] = B_cnt[i-1] + A_cnt[i-1];
    }
    cout << A_cnt[N] << " " << B_cnt[N] << endl;
    return 0;
}
