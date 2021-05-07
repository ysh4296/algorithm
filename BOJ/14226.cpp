#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 2000
using namespace std;
class Imo{
    private:
    public:
    int screen;
    int clip;
    int time;
    Imo(int s,int c,int t){
        this->screen = s;
        this->clip = c;
        this->time = t;
    }
};
int visit[MAX][MAX];//time
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int S;
    cin >> S;
    memset(visit,0,sizeof(visit));
    queue<Imo> q;
    q.push(Imo(1,0,0));
    while(!q.empty()){
        Imo cur = q.front();
        q.pop();
        if(visit[cur.screen][cur.clip] != 0) continue;
        visit[cur.screen][cur.clip] = cur.time;
        if(cur.screen < MAX)
        q.push(Imo(cur.screen,cur.screen,cur.time+1));
        if(cur.screen-1 >= 0)
        q.push(Imo(cur.screen-1,cur.clip,cur.time+1));
        if(cur.screen + cur.clip < MAX)
        q.push(Imo(cur.screen + cur.clip,cur.clip,cur.time+1));
    }
    int ans = 1e9;
    for(int i = 0 ; i < MAX ; i++){
        if(visit[S][i] == 0) continue;
        ans = min(ans,visit[S][i]);
    }
    cout << ans;
    
    return 0;
}
