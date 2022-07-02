#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<pair<int,int>, int> iii;
typedef pair<int, int> ii;
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int answer = 0;

   int N, K;
   cin >> N >> K;
   vector<iii> dp; // dp[hp] = {{lost_hp,waste},saved_people} 
   dp.push_back({ {0,0},0 });
   vector<ii> city;
   int A[21];
   int P[21];
   for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      A[i] = a;
   }
   for (int i = 0; i < N; i++) {
      int p;
      cin >> p;
      P[i] = p;
   }
   for (int i = 0; i < N; i++) {
      city.push_back({ A[i],P[i] });
   }

   sort(city.begin(), city.end());

   for (int i = 0; i < N; i++) {
      ii cur_city = city[i];
      int dp_size = (int)dp.size();
      for (int j = 0; j < dp_size; j++) {
         iii cur_dp = dp[j]; 
         if (cur_dp.first.first + cur_dp.first.second + cur_city.first <= K) { // untill die
            dp.push_back({ {cur_dp.first.first + cur_dp.first.second + cur_city.first, cur_dp.first.second + cur_city.first }, cur_dp.second + cur_city.second});
            answer = max(answer, cur_dp.second + cur_city.second);
         }
      }
   }

   cout << answer;

   return 0;
}
/*
문제를 읽는 능력이 너무 떨어졌다...
지금까지 들렸던 마을이 앞으로 전투에 영향을 끼치는것은 맞지만
지금까지 소모했던 체력이 기준이 아니기에...ㅜㅜ
*/
