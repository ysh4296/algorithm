#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<pair<int,int>,pair<int,int>> ii;
int rn[] = {-1,-2,1,2};
int cn[] = {2,1,2,1};
int N,M;
bool in_line(int r,int c){
    if((r <  N&& r >= 0)&&(c < M && c >= 0)) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int board[N][M] = {0,};
    queue<ii> q;
    q.push({{1,0},{N-1,0}});
    int ans = 1;
    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        if(board[cur.second.first][cur.second.second] == cur.first.first) continue;
        board[cur.second.first][cur.second.second] = cur.first.first;
        if(cur.first.second == 15 || cur.first.first <= 4)ans = max(ans,cur.first.first);
        for(int i = 0 ; i < 4 ; i++){
            if(in_line(cur.second.first + rn[i],cur.second.second + cn[i])){
                q.push({{cur.first.first+1,cur.first.second|(1<<i)},{cur.second.first + rn[i],cur.second.second + cn[i]}});
            }        
        }
    }
    cout << ans;
    return 0;
}
