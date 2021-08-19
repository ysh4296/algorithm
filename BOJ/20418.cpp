#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
#define mp make_pair
using namespace std;
typedef pair<int, int> ii;
ii in[50505][14];
int sc[50505][3]; //(#sol, panalty,submission index(time))
int pts[50505];
int MAX = 1 << 20;
vector<int> tree(2100000, 0);
vector<pair<ii, ii>> Vx;
void update(int p,int dif) {
    p += MAX;//the p's index 
    tree[p] += dif;
    for (p /= 2; p; p /= 2) tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
int get_right_most() {
    int p = 1;
    while (p < MAX) {
        if (tree[p * 2+1]) p = 2*p + 1;
        else p *= 2;
    }
    return p;
}
int sum(int l,int r) { // get sum between l,r
    l += MAX;
    r += MAX;
    int result = 0;
    for (; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1)result += tree[l++];
        if (r % 2 == 0)result += tree[r--];
    }
    return result;
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int st = M+1;
    memset(in, 0, sizeof(in));
    memset(sc, 0, sizeof(sc));
    for (int i = 0; i < M; i++) {
        int h, m, id, p, s;
        scanf("%d:%d %d %d %d", &h, &m, &id, &p, &s);
        if (h * 60 + m > 180) st = min(st,i);
        in[id][p] = ii(h*60 + m + (s-1)*20, i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 13; j++) {
            if (in[i][j].first == 0) continue;// unsolved
            if (in[i][j].second < st) {
                sc[i][0]++;// #sol ++
                sc[i][1] += in[i][j].first; // panalty add
                sc[i][2] = max(sc[i][2], in[i][j].second);// adjust max time
            }
        }
    }
    for (int i = 1; i <= N ; i++) Vx.push_back({ ii(-sc[i][0],sc[i][1]),ii(sc[i][2],i) });
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 13; j++) {
            if (in[i][j].first == 0 || in[i][j].second < st) continue;
            sc[i][0]++;
            sc[i][1] += in[i][j].first;
            sc[i][2] = max(sc[i][2], in[i][j].second);
            Vx.push_back({ ii(-sc[i][0],sc[i][1]),ii(sc[i][2],i) });
        }
    }
    sort(Vx.begin(),Vx.end());
    memset(sc, 0, sizeof(sc));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 13; j++) {
            if (in[i][j].first == 0) continue;
            if (in[i][j].second < st) {
                sc[i][0]++;// #sol ++
                sc[i][1] += in[i][j].first; // panalty add
                sc[i][2] = max(sc[i][2], in[i][j].second);// adjust max time
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        pair<ii, ii> temp = { ii(-sc[i][0],sc[i][1]),ii(sc[i][2],i) };
        int id = lower_bound(Vx.begin(), Vx.end(), temp) - Vx.begin();
        update(id, 1);
    }
    vector<int> score;
    int pos[50505];
    int pts[50505];
    memset(pos, 0, sizeof(pos));
    memset(pts, 0, sizeof(pts));
    vector<int> vl;
    while (tree[1]) { // there's item
        int p = get_right_most();
        int n = Vx[p - MAX].second.second;
        while (1) {
            if (pos[n] == 13) {
                update(p - MAX, -1);
                vl.push_back(n);
                break;
            }
            pos[n]++;
            if (in[n][pos[n]].first == 0 || in[n][pos[n]].second < st) continue;
            sc[n][0]++;
            sc[n][1] += in[n][pos[n]].first;
            sc[n][2] = max(sc[n][2], in[n][pos[n]].second);
            pair<ii, ii> temp = { ii(-sc[n][0],sc[n][1]),ii(sc[n][2],n) };
            int id = lower_bound(Vx.begin(), Vx.end(), temp) - Vx.begin();
            update(p - MAX, -1);
            pts[n] += sum(id + 1, p - MAX -1);
            update(id, 1);
            break;
        }
    }
    int answer = vl[0];
    for (int i = 0; i < N; i++) {
        if (pts[answer] <= pts[vl[i]]) {
            answer = vl[i];
        }
    }
    printf("%d\n",answer);
    return 0;
}
