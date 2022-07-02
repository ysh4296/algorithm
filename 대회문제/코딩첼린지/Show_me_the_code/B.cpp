#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
typedef pair<pair<int,int>, int> iii;
typedef pair<int, int> ii;

int line[7][7][7];
vector <ii> erase_v;
int balls[7] = { 0, };
int cur_sim = 2;
int p;


void cal_col() {
	stack<ii> s;
	for (int i = 0; i < 7; i++) { // row
		for (int j = 0; j < 7; j++) { // col
			if (line[cur_sim][i][j]!= 0) {
				s.push({ line[cur_sim][i][j] ,j});
			}
			else {
				int group_size = (int)s.size();
				while (!s.empty()) {
					ii cur = s.top();
					s.pop();
					if (cur.first == group_size) {
						erase_v.push_back({ i,cur.second});
					}
				}
			}
		}
		int group_size = (int)s.size();
		while (!s.empty()) {
			ii cur = s.top();
			s.pop();
			if (cur.first == group_size) {
				erase_v.push_back({ i,cur.second });
			}
		}
	}
	return;
}

void cal_row() {
	stack<ii> s;
	for (int j = 0; j < 7; j++) { // col
		for (int i = 0; i < 7; i++) { // row
			if (line[cur_sim][i][j]!=0) {
				s.push({ line[cur_sim][i][j] ,i});
			}
			else {
				int group_size = (int)s.size();
				while (!s.empty()) {
					ii cur = s.top();
					s.pop();
					if (cur.first == group_size) {
						erase_v.push_back({ cur.second,j });
					}
				}
			}
		}
		int group_size = (int)s.size();
		while (!s.empty()) {
			ii cur = s.top();
			s.pop();
			if (cur.first == group_size) {
				erase_v.push_back({ cur.second,j });
			}
		}
	}
	return;
}

void simulate() {
	for (int i = 6; i >= 0; i--) {
		if (line[cur_sim][i][cur_sim] == 0) {
			line[cur_sim][i][cur_sim] = p;
			break;
		}
	}
	while (true) {
		cal_col();
		cal_row();

		if (erase_v.empty()) break;
		sort(erase_v.begin(), erase_v.end(),greater<>());
		while (!erase_v.empty()) {
			ii cur = erase_v.back();
			erase_v.pop_back();
			if(line[cur_sim][cur.first][cur.second] != 0) balls[cur_sim]--;
			line[cur_sim][cur.first][cur.second] = 0;
			for (int i = cur.first; i > 0; i--) {
				line[cur_sim][i][cur.second] = line[cur_sim][i -1][cur.second];
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int answer = 1e9;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			int a;
			cin >> a;
			for (int k = 0; k< 7; k++) {
				line[k][i][j] = a;
				if(a != 0)
					balls[k]++;
			}
		}
	}
 	cin >> p;
	
	for (int i = 0; i < 7; i++) {
		cur_sim = i;

		simulate();
		
		answer = min(answer, balls[i]);
	}
	simulate();

	cout <<  answer + 1;

	return 0;
}

/*
시뮬레이션을 노가다 두뇌 차력쇼라 생각한것이 원인이 되어

시간이 매몰되어버렸다
*/
