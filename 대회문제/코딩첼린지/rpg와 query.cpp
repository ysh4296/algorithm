#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 1e9
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
    LL MAX = z*z;
    LL dp[n][MAX];
    LL ans[MAX];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < MAX ; j++){
            dp[i][j] = INF;
        } 
    }
    for(int i = 0 ; i < MAX ; i++){
        ans[i] = INF;
    }
    vector<point> Edge[n]; //next city, spend coin,0
    for(vector<int> road : roads){
        Edge[road[0]].push_back(point((LL)road[1],(LL)road[2],0));
    }
    queue<point> q;
    point start = point(0,0,0);
    q.push(start);
    while(!q.empty()){
        point cur = q.front(); q.pop();
        if(cur.coin >= MAX) continue;
        if(ans[cur.coin] > cur.day) {
            ans[cur.coin] = cur.day;
            for(int next_city = 0 ; next_city < n ; next_city++){ // type 3
                q.push(point(next_city, cur.coin, cur.day+1));
            }
        }
        if(dp[cur.city][cur.coin] < cur.day) continue;
        dp[cur.city][cur.coin] = cur.day;
        for(point next_city : Edge[cur.city]){ //type 1
            q.push(point(next_city.city, cur.coin + next_city.coin, cur.day+1));
        }
    }
    for(int i = z ; i < MAX ; i++){ // type 2
        if(ans[i-z] == INF) continue;
        ans[i] = min(ans[i],ans[i-z] + 1);
    }
    for(LL tcoin : queries){
        LL div = 0;
        LL temp = tcoin%(z);
        LL sol = 100000000000000001;
        for(LL i = 0 ; i < z ; i++){
            if(ans[temp+i*z] != INF){
                div = (LL)(tcoin - tcoin%z)/z;
                if(sol > ans[temp + i*z]+div-i)
                sol = ans[temp + i*z]+div-i;
            }
        }
        if(sol == 100000000000000001){
            answer.push_back(-1);
        } else {
            answer.push_back(sol);
        }
    }
    return answer;
}
