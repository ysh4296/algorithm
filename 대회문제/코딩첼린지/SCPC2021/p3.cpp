/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> ii;

vector<int>Bridge[501];
string Answer;
vector<int>Edge[501];
bool Visit[501];
vector<ii> Bridge_Pair;

bool cycle_find(int cur, int dest) {
	if (cur == dest) {
		return true;
	}
	if (Visit[cur]) return false;
	Visit[cur] = true;
	for (int i = 0; i < Edge[cur].size(); i++) {
		if (Visit[Edge[cur][i]]) continue;
		if (cycle_find(Edge[cur][i], dest)) return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, test_case;

	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, K;
		cin >> N >> M >> K;
		for (int i = 0; i <= N; i++) {
			Edge[i].clear();
			Bridge[i].clear();
		}

		Bridge_Pair.clear();

		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			Edge[u].push_back(v);
		}

		for (int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			Bridge[u].push_back(v);
			Bridge_Pair.push_back({ u,v });
		}

		Answer = "";
		for(int i = 0; i < K; i++) {
			memset(Visit, 0, sizeof(Visit));
			int start = Bridge_Pair[i].second, end = Bridge_Pair[i].first;
			for (int j = 0; j < (int)Bridge[end].size(); j++) {
				if (Bridge[end][j] == start) { Bridge[end].erase(Bridge[end].begin() + j); break; }
			}
			if (cycle_find(start, end)) {
				Edge[start].push_back(end);
				Answer += '1';
			}
			else {
				Edge[end].push_back(start);
				Answer += '0';
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0; // Your program should return 0 on normal termination.
}
/* 
사전순 최소의 정답을 찾기위해 가장 높은 unDirectedEdge부터 방향을 정하면서 간다
꼬여서 돌아가서 풀어나가야하나? 아니다 만약 돌아가서 풀어야하는 경우가 있다면 이미 해당 간선을 제외하고도 cycle이 연결된경우
따라서 문제 자체를 그리디하게 풀이할 수 잇다.
*/
