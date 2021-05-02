#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int,int> ii; // num of song,volume

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,S,M;
    cin >> N >> S >> M;
    int v[N] = {0,};
    for(int i = 0 ; i < N ; i++){
        cin >> v[i];
    }
    int VV[N+1][M+1] = {0,};
    memset(VV,0,sizeof(VV));
    VV[0][S] = 1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j <= M ; j++){
            if(VV[i][j] == 1){
                if(j+v[i] <= M)
                VV[i+1][j+v[i]] = 1;
                if(j-v[i] >= 0)
                VV[i+1][j-v[i]] = 1;
            }
        }
    }
    int ans = -1;
    for(int i = M ; i >= 0 ; i--){
        if(VV[N][i] == 1){
            ans = i;
            break;    
        }
    }
    cout << ans;
    return 0;
}
