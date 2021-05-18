#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
struct point{
    LL city;
    LL coin;
    LL day;
    point(LL ci , LL co , LL da){
        city = ci;
        coin = co;
        day = da;
    }
};
vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    vector<long long> answer;
    LL MAX = z*z+1;
    LL dp[n][MAX];
    LL ans[MAX];
    fill(dp[0] , dp[0] + n*MAX , 2555);
    fill(ans , ans + MAX , 2555);
    vector<point> Edge[n]; //next city, spend coin,0
    for(int i = 0 ; i < (int)roads.size() ; i++){
        Edge[roads[i][0]].push_back(point(roads[i][1],roads[i][2],0));
    }
    queue<point> q;
    point start = point(0,0,0);
    q.push(start);
    while(!q.empty()){
        point cur = q.front(); q.pop();
        if(cur.coin >= MAX) continue;
        if(dp[cur.city][cur.coin] <= cur.day) continue;
        dp[cur.city][cur.coin] = cur.day;
        if(ans[cur.coin] > cur.day) {
            ans[cur.coin] = cur.day;
            for(int next_city = 0 ; next_city < n ; next_city++){ // type 3
                if(next_city == cur.city) continue;
                q.push(point(next_city,cur.coin,cur.day+1));
            }
        }
        for(point next_city : Edge[cur.city]){ //type 1
            q.push(point(next_city.city,cur.coin + next_city.coin,cur.day+1));
        }
    }
    for(int i = z ; i <= MAX ; i++){ // type 2
        if(ans[i-z] + 1 > 2555) continue;
        ans[i] = min(ans[i],ans[i-z] + 1);
    }
    for(LL tcoin : queries){
        LL div = 0;
        if(ans[tcoin % (MAX-1)] < 2555){
            if(tcoin >= MAX-1){
                div = ((tcoin) - (tcoin%(MAX-1)))/z;
            }
            answer.push_back(ans[tcoin%(MAX-1)] + div);
        }
        else
            answer.push_back(-1);
    }
    return answer;
}
