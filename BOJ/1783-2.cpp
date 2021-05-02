#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int ans = 1;
    if(N == 1) ans = 1;//N == 1  no move
    if(N == 2){//N == 2  move 2,3
        ans = min((M+1)/2,4);
    }
    if(N >= 3 && M <= 6){//N >= 3 every move
        ans = min(4,M);
    } else if(N >= 3 && M > 6){
        ans = M-2;
    }
    cout << ans;
    return 0;    
}
