#include<iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX 1e9
class adj {
private:
	int v, w;
public:
	adj(int V,int W) {
		this->v = V;
		this->w = W;
	}
};
class city {
private:
	int city_num;
public:
	vector<adj> adj_list;
	int dist[101];
	int prev[101];
	city(int num) {
		this->city_num = num;
		for (int i = 0; i <= 100; i++) {
			dist[i] = MAX;
			prev[i] = 0;
			if (i == city_num) {
				dist[i] = 0;
				prev[i] = i;
			}
		}
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int u, v, w;
	vector<city> CityList;
	for (int i = 0; i <= n ; i++) {
		CityList.push_back(city(i));
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		if (CityList[u].dist[v] < w) continue;
		CityList[u].adj_list.push_back(adj(v,w));
		CityList[u].dist[v] = w;
		CityList[u].prev[v] = u;
	}
	for (int k = 1; k <= n; k++) {// across node
		for (int i = 1; i <= n; i++) { // start node
			for (int j = 1; j <= n; j++) { // end node
				if (CityList[i].dist[k] + CityList[k].dist[j] < CityList[i].dist[j]) {
					CityList[i].dist[j] = CityList[i].dist[k] + CityList[k].dist[j];
					CityList[i].prev[j] = CityList[k].prev[j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) { // start node
		for (int j = 1; j <= n; j++) { // end node
			if (CityList[i].dist[j] == MAX) {
				cout << 0 << " ";
				continue;
			}
			cout << CityList[i].dist[j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || CityList[i].dist[j] == MAX) {
				cout << 0 << endl;
				continue;
			}
			int start = i;
			int end = j;
			int p = j;
			stack<int> list;
			while (1) {
				list.push(CityList[i].prev[p]);
				p = CityList[i].prev[p];
				if (p == i) break;
			}
			cout << (int)list.size() + 1 << " ";
			while (!list.empty()) {
				cout << list.top() << " ";
				list.pop();
			}
			cout << j << endl;
		}
	}
	return 0;
}

//가장 기본적인 floidwashal algorithm
// 필요한 부분을 class로 구현했기때문에 알고리즘풀이라는 목표보다는 구조화에 초점을 
