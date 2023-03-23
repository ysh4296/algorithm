#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int N;
vector<int> v,sort_v;
map<int,int> next_value;// next_value[current] = nextValue
map<int,vector<int>> order; // key is value of index and value is the indexies of the array
vector<vector<int>> dp(101010,vector<int>(2,-1));
    
int lss(int idx, bool is_root, int same_count) { 
    if(dp[idx][is_root] != -1) return dp[idx][is_root];
    int value = v[idx];
    int res = 0;
    //when is the order value goes next?
    //it depends on weather current index is root or the last point of the v[idx] 
    
    // move to same value
    //find the next same value
    int next_order_idx = lower_bound(order[value].begin(),order[value].end(),idx) - order[value].begin();
    if(next_order_idx + 1 < (int)order[value].size()){ // there is next same value
        res = max(res,lss(order[value][next_order_idx + 1],is_root,same_count+1));
    }
    
    // move to next value 
    //find the next next value
    value = next_value[v[idx]];
    next_order_idx = lower_bound(order[value].begin(),order[value].end(),idx) - order[value].begin();
    if(next_order_idx < (int)order[value].size() && ( is_root || (same_count == (int)order[v[idx]].size()))){ // there is next next value
        res = max(res,lss(order[value][next_order_idx],false,1));
    }
    return dp[idx][is_root] = res + 1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        sort_v.push_back(temp);
        order[v[i]].push_back(i);
    }
    
    sort(sort_v.begin(),sort_v.end());
    sort_v.erase(unique(sort_v.begin(),sort_v.end()),sort_v.end());
    
    for(int i = 0 ; i < (int)sort_v.size() - 1 ; i++) {
        // cout << "current is : " << sort_v[i] << " // next is : " << sort_v[i+1] << endl;
        next_value[sort_v[i]] = sort_v[i+1];
    }
    
    int result = 0;
    
    for(int i = 0 ; i < N ; i++){
        result = max(result,lss(i,true,1));
    }
    
    cout << N - result << endl;
    
    return 0;
}

/*
오랜만에 풀어본 대회급 문제...
dp에서 저장하지 않는 조건이 메모이제이션함수에 매개변수로 들어가는 이유를 아직도 이해하긴 어렵다..
물론 결과적으로는 최대값이 제일 먼저 계산되는 형태가 될 것이기 때문에 dp배열을 구성하는것엔 문제가없지만...
한동안은 재활운동하는 샘으로 천천히 해야할 것 같다.
*/
