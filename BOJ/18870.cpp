#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <pair<int,int>> v;
vector <int> ans(1000000);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int x;
        cin >> x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end()); //sort
    int pi = v[0].first;
    int cnt = 0;
    ans[v[0].second] = 0;
    for(int i = 1 ; i < N ; i++){
        if(pi == v[i].first){
            ans[v[i].second] = cnt;
        } else {
            ans[v[i].second] = ++cnt;
            pi = v[i].first;
        }
    }
    for(int i = 0 ; i < N ; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
